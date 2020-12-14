import java.io.*;

class Empbase{
    final float da = 0.1;
    final float hra = 0.2;

    String name;
    String  empId;

    String phone;
    String adress;

    Empbase(String n, String id, String ad, String ph){
        this.name=n;
        this.empId=id;
        this.adress=ad;
        this.phone=ph;
    }

    void showSalary(int salary){
        System.out.println("salary: "+ (salary+salary*da+salary*hra));
    }

    String toString(){
        return "emp name: "+name+"  ,"+"emp ID: "+empId;
    }
}


class Office extends Empbase{
    String designation;

    Office(String name, String emp_id, String address, String phone,String designation) {
        super(name,emp_id,address,phone);
        this.designation = designation;
    }
}

class Administrative extends Office{
    int salary;
    public Technical(String name, String emp_id, String address, String phone,String designation){
       super(name, emp_id, address, phone, designation);
    }
}

class Accounts extends Office{
    int salary;
    public Accounts(String name, String emp_id, String address, String phone,String designation){
       super(name, emp_id, address, phone, designation);
    }
}

class MainA{
    static public void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true){
        System.out.println("Choose From below: ");
        System.out.println("1 Administrative");
        System.out.println("2 Accounts");
        System.out.println("3 Stop");
        String esac = br.readLine();


        System.out.println("Enter name :");
        String name = br.readLine();
        System.out.println("Enter adress :");
        String address = br.readLine();
        System.out.println("Enter phone number :");
        String phone = br.readLine();

        switch(esac){
            case '1':
            System.out.println(" Emp ID :");
            String id = br.readLine();

            System.out.println("Enter Designation :");
            String des = br.readLine();

            Administrative adm = new Administrative(name,id,address,phone,des);
            System.out.print(adm);

            System.out.println("Enter Salary :");
        int salary = Integer.parseInt(br.readLine());

            adm.showSalary(salary);

            break;
            case '2':
           
            System.out.println("Emp ID :");
            String id1 = br.readLine();
            System.out.println("Designation :");
            String des1 = br.readLine();
            
            Accounts acc = new Accounts(name,id,address,phone,des);
            System.out.print(acc);
            
            System.out.println("Enter Salary :");
        int salary = Integer.parseInt(br.readLine());

            acc.showSalary(salary);

            break;

            case "3": break;
            default:
                System.out.println("Choose from 1,2,3 ");
                break;
        }  
    } 
}

}