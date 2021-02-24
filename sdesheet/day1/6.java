import java.io.*;
import java.util.*;

class Range{
		int s,e;
		Range(int a, int b){ s=a; e=b; }
	}

class Six{

	static ArrayList<Range> merge(ArrayList<Range> intervals){
		ArrayList<Range> ans = new ArrayList<Range>();
		int i=-1;
		for(Range x: intervals){
			if(i==-1){
				i++;
				ans.add(x);
			}
			Range ctop = ans.get(i);
			if(x.s<=ctop.e && ctop.e<x.e) ans.set(i, ctop);
			else{
				ans.add(x);
				i++;
			}
		}
		return ans;
	}

	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<Range> ip = new ArrayList<Range>();
		ip.add(new Range(1,9));
		ip.add(new Range(2,4));
		ip.add(new Range(4,7));
		ip.add(new Range(6,8));

		for(Range x: merge(ip)) System.out.println(x.s+" "+x.e);
	
	}
}