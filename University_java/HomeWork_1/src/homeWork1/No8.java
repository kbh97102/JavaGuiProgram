package homeWork1;

import java.util.Scanner;

public class No8 {

	public static void main(String[] args) {
		
		Scanner scanf = new Scanner(System.in);
		int maxIndex;
		int randomNumber;
		int arrayLastIndex=0;
		int checkIndex=0;
		
		System.out.print("정수 몇개?");
		maxIndex = scanf.nextInt();
		
		if(maxIndex >= 100) {
			System.out.println("100보다 작은 수를 입력하시오.");
			maxIndex = scanf.nextInt();
		}
		
		int[] intArray = new int[maxIndex];

		while (arrayLastIndex < maxIndex) {
			randomNumber = (int) (Math.random() * 100) + 1;
			while (checkIndex < arrayLastIndex) {
				if (randomNumber == intArray[checkIndex]) {
					randomNumber = (int) (Math.random() * 100) + 1;
					checkIndex = 0;
				}
				checkIndex++;
			}
			checkIndex = 0;
			intArray[arrayLastIndex++] = randomNumber;
		}
		for(int i=0;i<maxIndex;i++) {
			if(i%10 == 0 && i !=0) {
				System.out.printf("\n%-2d ", intArray[i]);
			}
			else {
				System.out.printf("%-2d ", intArray[i]);
			}
		}
		
		scanf.close();
	}

}
