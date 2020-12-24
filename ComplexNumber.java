import java.lang.Math;

public class ComplexNumber {
	double Real_Part;
	double Imaginary_Part;
	static final double EPSILON=0.001;
	
	public ComplexNumber(double real_part,double imaginary_part) {
		this.Imaginary_Part=imaginary_part;
		this.Real_Part=real_part;	
	}
	
	public ComplexNumber plus(ComplexNumber num_to_add) {
		ComplexNumber sum=new ComplexNumber(num_to_add.Real_Part,num_to_add.Imaginary_Part);
		sum.Real_Part=Real_Part+num_to_add.Real_Part;
		sum.Imaginary_Part=Imaginary_Part+num_to_add.Imaginary_Part;
		return sum;
	}
	
	public ComplexNumber minus(ComplexNumber num_to_sub) {
		ComplexNumber sub=new ComplexNumber(num_to_sub.Real_Part,num_to_sub.Imaginary_Part);
		sub.Real_Part=Real_Part-num_to_sub.Real_Part;
		sub.Imaginary_Part=Imaginary_Part-num_to_sub.Imaginary_Part;
		return sub;
	}
	public ComplexNumber times (ComplexNumber num_to_mult) {
		ComplexNumber result_num=new ComplexNumber(num_to_mult.Real_Part,num_to_mult.Imaginary_Part);
		result_num.Real_Part=this.Real_Part*num_to_mult.Real_Part - this.Imaginary_Part*num_to_mult.Imaginary_Part;
		result_num.Imaginary_Part=this.Real_Part*num_to_mult.Imaginary_Part + this.Imaginary_Part*num_to_mult.Real_Part;
		return result_num;
	}
	
	public ComplexNumber devide (ComplexNumber num_to_dev) {
		ComplexNumber result_num=new ComplexNumber(num_to_dev.Real_Part,num_to_dev.Imaginary_Part);
		result_num.Real_Part=(this.Real_Part*num_to_dev.Real_Part - this.Imaginary_Part*num_to_dev.Imaginary_Part)/(num_to_dev.Imaginary_Part*num_to_dev.Imaginary_Part+num_to_dev.Real_Part*num_to_dev.Real_Part);
		result_num.Imaginary_Part=(this.Real_Part*num_to_dev.Imaginary_Part + this.Imaginary_Part*num_to_dev.Real_Part)/(num_to_dev.Imaginary_Part*num_to_dev.Imaginary_Part+num_to_dev.Real_Part*num_to_dev.Real_Part);
		return result_num;
	}
		
	public double getRealPart() {
		return Real_Part;
	}
	
	public double getImaginaryPart() {
		return Imaginary_Part;
	}
	
	public double getRadius() {
		return Math.sqrt(Math.pow(Imaginary_Part,2) + Math.pow(Real_Part,2));
	}
	
	public double getArgument() {
		return Math.atan2(Imaginary_Part,Real_Part);
	}
	
	public boolean almostEquals (ComplexNumber other) {
		ComplexNumber remainder = this.minus(other);
		if (remainder.getRadius()>EPSILON) {
			return false;
		}
		return true;
	}
	


}
