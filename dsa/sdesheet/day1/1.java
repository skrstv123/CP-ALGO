import java.io.*;
class One{

	public static int FIndDuplicate(int[] nums){
		int slow = nums[0];
		int fast = nums[0];
		do{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}while(slow!=fast);

		fast = nums[0];
		while(slow!=fast){
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}

	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] nums = {1,2,3,2};
		System.out.println(One.FIndDuplicate(nums));
	}
}