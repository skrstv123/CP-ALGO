
import java.io.BufferedReader;

import java.io.*;

class Prime implements Runnable {
    long j, c, m, n;

    Prime(int x,int a) {
        super();
        c = 0;
        n = a;
        m=x;

    }

    public void run() {
        for (long i = m; i <= n; i++) {

            for (j = 2; j <= i; j++) {
                if (i % j == 0)
                    break;
            }
            if (j == i) {
                c++;
                System.out.println(c + "th" + " Prime no: = " + i);
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    
                }
    			}	
    		}	
    	}  
}
 
class Fib implements Runnable
{
	long a,b,c,n,m;
	Fib(int x)
	{
		a=c=n=0;
        b=1;
        m = x;
	}
	public void run()
	{
		while(n++<m)
		{
			System.out.println(n+"th" +" Fib no: = "+a);
			c=a+b;
			a=b;
			b=c;
			try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                
            }
		}	
	}
}
 
public class MyPriFib {
 
	public static void main(String[] args) throws IOException{
		// Thread ct=Thread.currentThread();
        // System.out.println("Main thread name : "+ct.getName());	
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Upper bound and Lower Bound of Prime Nos");
        int a=Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());
        System.out.println("Fibonacci Series range");
        int b=Integer.parseInt(br.readLine());
		Prime p=new Prime(a,c);
		Fib f=new Fib(b);
		Thread fib=new Thread(f,"fibonacci");
		Thread prime=new Thread(p,"prime");
		fib.start();
		System.out.println("Thread "+ fib.getName() + " started.");
		prime.start();	
		System.out.println("Thread "+ prime.getName() + " started.");	
	}
}