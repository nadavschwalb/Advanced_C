#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define PORT_LEN 64


#define PORT_LEN 64
int share_port_file(int port_number,FILE* fp){
  if(fp == NULL){
     printf("error: %s\n",strerror(errno));
  }
  char port_str[PORT_LEN];
  snprintf(port_str,PORT_LEN,"%d\n",port_number);
  if(fputs(port_str,fp)<0){
    printf("error: %s\n",strerror(errno));
    return -1;
  }
  else return 0;
}

int rand_in_range(int lower, int upper){
  int res = 0;
  while (1){
    res = rand();
    if(res<upper && res>lower) return res;
  } 
}

