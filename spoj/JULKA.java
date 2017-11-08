import java.util.*;
import java.lang.*;
import java.math.BigInteger;
 
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner leer = new Scanner(System.in);
		BigInteger x,y,n,k;
		BigInteger dos= new BigInteger("2");
		int t=10;
		for(int i=0;i<t;i++)
		{
			x= leer.nextBigInteger();
			y= leer.nextBigInteger();
			n= x.subtract(y);
			n= n.divide(dos);
			k= x.subtract(n);
			System.out.println(k);
			System.out.println(n);
		}
		leer.close();
	}
} 
