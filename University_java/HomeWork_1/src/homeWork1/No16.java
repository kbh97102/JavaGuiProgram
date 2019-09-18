package homeWork1;

import java.util.Scanner;

public class No16 {

	public static void main(String[] args) {
		
		Scanner scanf = new Scanner(System.in);
		String cases[] = {"가위", "바위", "보"};
		String endCondition = "그만";
		String user;
		int computersPick;
		int usersPick=0;
		
		System.out.println("컴퓨터와 가위 바위 보 게임을 합니다.");
		System.out.print("가위 바위 보!>>");
		
		
		user = scanf.next();
		
		
		while(true) {
			
			
			for(int i=0;i<3;i++) {
				if(user.equals(cases[i]) == true) {
					usersPick = i;
					break;
					//System.out.println(cases[i]);
				}
			}
			
			computersPick = (int)(Math.random()*3);
			if(computersPick == usersPick) {
				System.out.println("사용자  = "+cases[usersPick]+" , 컴퓨터 = "+cases[computersPick]+", 비겼습니다.");
			}
			else if(computersPick == 0) {
				if(usersPick == 1) {
					System.out.println("사용자  = "+cases[usersPick]+" , 컴퓨터 = "+cases[computersPick]+", 사용자가 이겼습니다.");
				}
				else if(usersPick == 2) {
					System.out.println("사용자  = "+cases[usersPick]+" , 컴퓨터= "+cases[computersPick]+", 사용자가 졌습니다.");
				}
			}
			else if(computersPick == 1) {
				if(usersPick == 0) {
					System.out.println("사용자  = "+cases[usersPick]+" , 컴퓨터 = "+cases[computersPick]+", 사용자가 졌습니다.");
				}
				else if(usersPick == 2) {
					System.out.println("사용자  = "+cases[usersPick]+" , 컴퓨터 = "+cases[computersPick]+", 사용자가 이겼습니다.");
				}
			}
			else if(computersPick == 2) {
				if(usersPick == 0) {
					System.out.println("사용자  = "+cases[usersPick]+" , 컴퓨터 = "+cases[computersPick]+", 사용자가 이겼습니다.");
				}
				else if(usersPick == 1) {
					System.out.println("사용자  = "+cases[usersPick]+" , 컴퓨터 = "+cases[computersPick]+", 사용자가 졌습니다.");
				}
			}
			System.out.print("가위 바위 보!>>");
			user = scanf.next();
			if(user.equals(endCondition) == true) {
				System.out.println("게임을 종료합니다...");
				break;
			}
		}
		scanf.close();
	}

}
