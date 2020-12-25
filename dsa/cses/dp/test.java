import java.io.*;
import java.util.*;

public class Main
{
  static class edge
  {
    int src;
    int dest;
    long weight;

    edge(int src,int dest , long weight)
    {
        this.src = src;
        this.dest = dest;
        this.weight =weight;
    }


  }

  static long diff(ArrayList<Integer> x , ArrayList<Integer> y)
  { long diff = 0;
    for(int i = 0;i<x.size();i++)
    {
        diff += Math.abs(x.get(i) - y.get(i));
    }
    return diff;
  }

  static void primMST(long graph[][])
  {
    int v = graph.length;
    System.out.println(v);
    int parent[] = new int[v];
    long key[]  = new long[v];
    boolean mstset[] = new boolean[v];

    for(int i = 1;i<v;i++)
    {
        key[i] = Integer.MIN_VALUE;
        mstset[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for(int c= 0;c <v-1;c++)
    {
        long u = maxkey(key,mstset,v);
        mstset[(int) u] = true;
        for(int j = 0;j<v;j++)
        {
            if(graph[(int) u][j] != 0 && mstset[j] == false && graph[ (int) u][j] > key[j])
            {
                parent[j] = (int) u;
                key[j] = graph[(int) u][j];
            }
        }


    }
    printMST(parent, graph ,v);
    //printM(parent , graph);

  }
    static void printMST(int[] parent, long [][] graph ,int v)
    {
        long sum  = 0;
        for(int i = 0;i<v;i++)
        {
            sum += graph[parent[i]][i];
        }
        System.out.println(sum);

    }
    static void printM(int parent[],long graph[][])
    {
       System.out.println("Edge  weight");
       for(int i = 1;i<graph.length;i++)
       {
           System.out.println(parent[i] + "-" + i + "/t" + graph[parent[i]][i]);
       } 
    }
     static long maxkey(long[] key , boolean[] mstset,int v)
    {
        long mx = Integer.MIN_VALUE;
        int index = -1;
        for(int i = 0;i< v ; i++)
        {
            if(mstset[i] == false && key[i] > mx)
            {
                mx = key[i];
                index  = i;
            }
        }
        return index;
    } 


    public static void main(String [] args) throws IOException
    {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        String nd[] = br.readLine().split(" ");
        int n = Integer.parseInt(nd[0]);
        int d = Integer.parseInt(nd[1]);
        // System.out.println(n);
        // System.out.println(d);
        ArrayList<ArrayList<Integer>> li = new ArrayList<>();
        for(int i = 0;i<n ;i++)
        {
            String str[] =   br.readLine().split(" ");
            ArrayList<Integer> values = new ArrayList<>();
            for(int k =0 ;k<str.length;k++)
            {
                values.add(Integer.parseInt(str[k]));
            }
            li.add(values);
            //System.out.println(li);

        }
        ArrayList <edge> edges = new ArrayList<>();

        for(int i = 0 ;i<n ;i++ )
        {
            for(int j = i+1;j<n;j++)
            {
                long weight = diff(li.get(i),li.get(j));
                edge curr = new edge(i,j,weight);
                edges.add(curr);
                //System.out.println(curr);
            }
        }
        long graph[][] =new long[n][n];

        for(int i = 0;i<edges.size();i++)
        {
            graph[edges.get(i).src][edges.get(i).dest] = edges.get(i).weight;
            graph[edges.get(i).dest][edges.get(i).src] = edges.get(i).weight;
        }
        primMST(graph);
        //System.out.println("okkkk");



    }




} 