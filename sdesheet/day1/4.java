import java.io.*;
import java.util.*;
class Four{

	static int half(int x){ if(x%2==1) x++; return x/2; }

	public static void merge1(int[] a, int[] b){
		// insertion O(n.m)
		for(int i=0;i<a.length; i++){
			if(a[i]>b[0]){
				int tmp = a[i];
				a[i] = b[0];
				b[0] = tmp;
				int j=1;
				if(b.length>1){
					while(b[j]<tmp){
						b[j-1] = b[j];
						j++;
						if(j>=b.length) break;
					}
					b[j-1] = tmp;
				}
			}
			for(int i1=0;i1<a.length;i1++) System.out.print(a[i1]+  " ");
				System.out.println();
			for(int i2=0;i2<b.length;i2++) System.out.print(b[i2]+  " ");
				System.out.println("\n--------------------");
		}		
		
	}
	public static void merge2(int[] a, int[] b){
		// gap method
		int gap = half(a.length + b.length);

		while(gap>1){
			int i=0, j=gap-1;
			boolean ib=false, jb = false;
			while(true){
				if(jb && j>=b.length) break;
				if(ib || i>=a.length){
					if(!ib){ib = true; i=0;}
					
					if(b[i]>b[j]){int tmp  = b[i];b[i] = b[j];b[j] = tmp;
					}
					
				}
				else if(jb || j>=a.length){
					if(!jb){jb=true; j=0;  }
					
					if(a[i]>b[j]){int tmp = a[i];a[i] = b[j];b[j] = tmp;
					}
				}
				else
					if(a[i]>a[j])	{int tmp  = a[i];a[i] = a[j];a[j] = tmp;}	
				i++;j++;
			}
			gap=half(gap);
		}
		for(int i1=0;i1<a.length;i1++) System.out.print(a[i1]+  " ");
				System.out.println();
		for(int i2=0;i2<b.length;i2++) System.out.print(b[i2]+  " ");
			System.out.println("\n--------------------");
		
	}

	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] a = {1,2,3,5,5,6};
		int[] b = {1,2,9};
		Four.merge2(a,b);
	
	}
}