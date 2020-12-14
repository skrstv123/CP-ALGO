class Complex{
   double my_real;
   double my_imag;

   Complex(double my_real, double my_imag){
      this.my_real = my_real;
      this.my_imag = my_imag;
   }

   Complex(Complex x){
      this.my_real = x.my_real;
      this.my_imag = x.my_imag;
   }

   Complex(){}

   Complex add(Complex n1, Complex n2){
      Complex temp = new Complex(0.0, 0.0);
      temp.my_real = n1.my_real + n2.my_real;
      temp.my_imag = n1.my_imag + n2.my_imag;
      return(temp);
   }

   Complex sub(Complex n1, Complex n2){
      Complex temp = new Complex(0.0, 0.0);
      temp.my_real = n1.my_real - n2.my_real;
      temp.my_imag = n1.my_imag - n2.my_imag;
      return(temp);
   }

   Complex mult(Complex n1, Complex n2){
      Complex temp = new Complex(0.0, 0.0);
      temp.my_real = n1.my_real*n2.my_real - n1.my_imag*n2.my_imag;
      temp.my_imag = n1.my_real*n2.my_imag + n2.my_real*n1.my_imag;
      return(temp);
   }
   void showComplex(Complex x){
      System.out.println(x.my_real + " + "?x.my_imag>=0:"" + x.my_imag+"i")
   }

   public static void main(String[] args){
      Complex n1 = new Complex(76.8, 24.0),
      n2 = new Complex(65.9, 11.23),
      temp;
      temp = add(n1, n2);
      System.out.printf("The sum of two complex numbers is %.1f + %.1fi", temp.my_real,
      temp.my_imag);
   }
   
}