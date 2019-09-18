package homeWork1;

import java.util.Scanner;

public class No3 {

	public static void main(String[] args) {
		
		Scanner scanf = new Scanner(System.in);
		int starLine;
		int starMax;
		
		System.out.print("정수를 입력하시오>>");
		starLine = scanf.nextInt();
		starMax = starLine;
		for(int i=0;i<starLine;i++) {
			for(int j=0;j<starMax;j++) {
				System.out.print("*");
			}
			System.out.println();
			starMax--;
		}
		
		scanf.close();
	}

}
