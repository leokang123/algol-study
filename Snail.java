import java.util.Scanner;

public class Snail {
    public static void main(String[] args) {
		//---------여기에 코드를 작성하세요.---------------//
    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
    	
    	int[] dx = {1, 0, -1, 0};
    	int[] dy = {0, 1, 0, -1};
    	for (int t = 0 ; t < n ; t++) {
    		int c = sc.nextInt();
    		int[][] arr = new int[c][c];
    		int cnt = c * c;
    		int cx = 0;
    		int cy = 0;
    		int dir = 0;
    		int num = 1;
    		while (true) {
				arr[cy][cx] = num++;
				cnt--;
				if (cnt == 0) break;
				while(true) {
					int tx = cx + dx[dir];
	    			int ty = cy + dy[dir];
	    			if (tx < 0 || ty < 0 || tx >= c || ty >= c) {
	    				dir = (dir + 1) % 4;
	    				continue;
	    			}
	    			if (arr[ty][tx] != 0)  {
	    				dir = (dir + 1) % 4;;
	    				continue;
	    			}
	    			cy = ty;
	    			cx = tx;
	    			break;
	    			
				}
    		}
    		for (int i = 0 ; i < c ; i++) {
    			for (int j = 0 ; j < c ; j++) {
    				System.out.print(arr[i][j] + " ");
    			}
    			System.out.println();
    		}

    	}
    }
}