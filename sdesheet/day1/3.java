import java.io.*;
import java.util.*;
class Three{

	public static void missrepeat(int[] nums){
		int n =  nums.length;
		int xxory = 0;
		for(int i=1;i<=n;i++) xxory^=i;
		for(int i: nums) xxory^=i;
		ArrayList<Integer> b1 = new ArrayList<Integer>();
		ArrayList<Integer> b2 = new ArrayList<Integer>();
		int msb=-1, xxory1 = xxory;
		while(xxory1>0){
			msb++;
			xxory1>>=1;
		}
		for(int i=1;i<=n;i++){
			if(((i>>msb)&1)==1)
				b1.add(i);
			else b2.add(i);
		}
		for(int i: nums){
			if(((i>>msb)&1)==1)
				b1.add(i);
			else b2.add(i);
		}
		int A=0,B=0;
		for(int i: b1) A^=i;
		for(int i: b2) B^=i;
		for(int i: nums){
			if((i^A)==0){System.out.println("missing "+ B + " repeating " + A); break;}
			if((i^B)==0){System.out.println("missing "+ A + " repeating " + B); break;}
		}
	}

	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] nums = {1,2,3,2};
		Three.missrepeat(nums);
	}
}