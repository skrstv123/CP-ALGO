
import java.io.*;
class Two{

	public static void sortzo(int[] nums){
		int l= 0;
		int m=0;
		int h = nums.length -1;
		int tmp;
		while(m<=h){
			switch(nums[m]){
				case 0:
					tmp = nums[l];
					nums[l] = nums[m];
					nums[m] = tmp;
					l++;
					m++;
					break;
				case 1:
					m++;
					break;
				case 2:
					tmp = nums[m];
					nums[m] = nums[h];
					nums[h] = tmp;
					h--;
					break; 
			}
		}
	}

	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] nums = {1,1,1,2,0,2,0,0,2};
		Two.sortzo(nums);
		for(int i=0;i<9;i++)System.out.print(nums[i] + " ");
	}
}