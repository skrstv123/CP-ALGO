/*1
Extended Euclidean algorithm

gcd(a,b) can be written as 
a.x + b.y = gcd(a,b)

Extended Euclidean algorithm also finds integer coefficients x and y

The extended Euclidean algorithm updates results of gcd(a, b) using the results calculated by recursive call gcd(b%a, a). Let values of x and y calculated by the recursive call be x1 and y1. x and y are updated using the below expressions.


x = y1 - b//a * x1
y = x1
 
*/
#include<iostream.h>



int d,x,y;
void gcdex( int a, int b)
{
	if(!b){
		d=a;
		x=1;
		y=0;
	}
	else{
		gcdex(b,  a%b);
		int temp= x;
		x=y;
		y=temp - (a/b)*y; 
	}
	
}

/*2
This algorithm is used when A and B are co-prime.
 In such cases, x becomes the multiplicative modulo inverse of A under modulo B, and y becomes the multiplicative modulo inverse of B under modulo A.
 This can be ubderstood better with the Modular multiplicative inverse .
*/


//int main()
//{
	//gcdex(45,48);
	//cout<< "gcd value is "<<d<<"\n";
	//cout<< "x, y = "<<x<<" " <<y;
//}

//Modular multiplicative inverse
// (a.b)%m = 1 // b is mul mod inv of a mod m 
//it exists iff gcd(a,m)=1
// so from gcdex a.x + m.y = 1 and somehow it is believed that mulmodinv b = x 

int d,x,y;
int mulmodinv(int A, int M)
{
    gcdex(A,M);
    return (x%M+M)%M;    //x may be negative
}

/*3
mulmodinv when m is a prime 

This approach uses Fermat's Little Theorem.

a^(m-1) ≡ 1 (mod m)  
If we multiply both sides with a-1, we get

 a^-1 ≡ a^( m-2) (mod m)   //explain how
 */
int gcd(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
int modexp(int b, int ex, int mod)
{
int res=1;
while(ex)
{
	if(ex&1)
		res=(res*b)%mod;
	b=(b*b)%mod;
	ex>>=1;
}
return res;	
}

void mulmodinv(int a, int m) 
{ 
    int g = gcd(a, m); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    {
        cout << "Modular multiplicative inverse is "
             << modexp(a, m-2, m); 
    } 
} 
