#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include <errno.h>
#include "port_share.h"



int main(int argc, char *argv[]){
  int server_port = 0, http_port = 0;

  FILE* fp_server_port = fopen("server_port","w");
  FILE* fp_http_port = fopen("http_port","w");
  char message[1025] = "GET /counter HTTP/1.1\r\nHost: nova.cs.tau.ac.il\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\nUser-Agent: Mozilla/5.0 )Windows NT 5.1( AppleWebKit/537.36 )KHTML, like Gecko(Chrome/31.0.1650.57 Safari/537.36\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: en-US,en;q=0.8,he;q=0.6\r\n\r\n";
  int server_socket = 0, http_socket = 0, connfd = 0;
  int connfd_index = 0;
  int connfd_arr[4] ={0}, http_connfd =0;
  struct sockaddr_in serv_addr , http_addr; 
  char server_sendBuff[1025];
  char http_sendBuff[1025];
  char recvBuff[1024];
  time_t ticks; 


  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(server_sendBuff, '0', sizeof(server_sendBuff)); 

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  


  http_socket = socket(AF_INET, SOCK_STREAM, 0);
  memset(&http_addr, '0', sizeof(http_addr));
  memset(http_sendBuff, '0', sizeof(http_sendBuff)); 

  http_addr.sin_family = AF_INET;
  http_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  while(1){ 
    server_port = rand_in_range(1024,64000);
    serv_addr.sin_port = htons(server_port);
    if(bind(server_socket, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0){
      printf("error: %s\n",strerror(errno));
      continue;
    }

    share_port_file(server_port,fp_server_port);
    fclose(fp_server_port);
    break;
  }

  while(1){
    http_port = rand_in_range(1024,64000);
    http_addr.sin_port = htons(http_port);
    if(bind(http_socket, (struct sockaddr*)&http_addr, sizeof(http_addr))<0){
      printf("error: %s\n",strerror(errno));
      continue;
    }

    share_port_file(http_port,fp_http_port);
    fclose(fp_http_port);
    break;
  }

  if(listen(server_socket, 10)){
    printf("error: %s\n",strerror(errno));
    return -1;
  }


  if(listen(http_socket, 10)){
    printf("error: %s\n",strerror(errno));
    return -1;
  }


  //server lives forever
  while(1)
  {
    while(connfd_index < 3){
        connfd_arr[connfd_index] = accept(server_socket, (struct sockaddr*)NULL, NULL); 
        if( connfd_arr[connfd_index]<0){
          printf("error: %s\n",strerror(errno));
          return -1;
        }
        connfd_index++;
    }
    // all clients conneced

    //connect to http socket

    http_connfd = accept(http_socket,(struct sockaddr*)NULL, NULL);
    if(http_connfd<0){
      printf("error: %s\n",strerror(errno));
      return -1;
    }   
    while(1){ 
          for(int i=0; i<3;i++){
              int n = 0;
              n = read(http_connfd,recvBuff,sizeof(recvBuff)-1);
              if(n==0){
                http_connfd = accept(http_socket,(struct sockaddr*)NULL, NULL);
                if(http_connfd<0){
                  printf("error: %s\n",strerror(errno));
                  return -1;
                }  
              }
              
              recvBuff[n] = '\0';
              while(strstr(recvBuff,"\r\n\r\n")==NULL){
                char tempBuff[1024];
                n = read(http_connfd,tempBuff,sizeof(tempBuff)-1);
                tempBuff[n] = '\0';
                strcat(recvBuff,tempBuff);
              }
            
            if(write(connfd_arr[i], recvBuff, strlen(recvBuff))<0){
              printf("error: %s\n",strerror(errno));
              return -1;
            } 

            n = read(connfd_arr[i], recvBuff, sizeof(recvBuff)-1);
            recvBuff[n] = '\0';

            write(http_connfd,recvBuff,strlen(recvBuff));

          }

        } 
      
      fclose(fp_http_port);
      close(http_connfd);
      for(int i=0;i<3;i++){
        close(connfd_arr[i]);
      }
    }
}
