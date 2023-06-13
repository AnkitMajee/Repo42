import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Prime{
	public static void main(String args[]) throws IOException{
		BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter the range of prime number = ");
		int n= Integer.parseInt(scan.readLine());
		System.out.print("Prime number are = ");	
		for(int i=2;i<=n;i++){
			int num=i;
			if(num==2){ System.out.print(num+" ");
			continue;
			}
			boolean flag=false;
			for(int j=2; j<num; j++){
                if(num%j == 0){
                    flag = true;
                    break;
                }
            }
            if(flag==false)
                System.out.print(num+" ");
        }
        scan.close();
		
	}
}