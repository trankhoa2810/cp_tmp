#include <stdio.h>

typedef struct {
	int F, S;
} ii;

int max(int a, int b) {
	if(a > b) return a;
	return b;
}

void debug(ii p) {
	printf("[ %d %d ]\n", p.F, p.S);
}

int has[1001][1001];

int main() {
	int n, m = -1;
	scanf("%d", &n);
	ii a[n];	
	for(int i = 0; i < n; i++) {		
		scanf("%d%d", &a[i].F, &a[i].S);			
		has[a[i].F][a[i].S] = 1;
		m = max(max(a[i].F, a[i].S), m);
	}
	/* a.Phan hoi */
	for(int i = 1; i <= m; i++) {
		if(has[i][i] != 1) {
			printf("Khong thoa: a. Phan hoi;\n");
			break;
		}
	}
	/* b.Doi xung */
	for(int i = 0; i < n; i++) {				
		if(has[a[i].S][a[i].F] != 1) {			
			printf("Khong thoa: b. Doi xung;\n");
			break;
		}
	}	
	/* c.Phan doi xung */
	for(int i = 0; i < n; i++) {				
		if(has[a[i].F][a[i].S]) {
			if(has[a[i].S][a[i].F]) {
				if(a[i].S == a[i].F) {
					continue;
				} else {
					printf("Khong thoa: c. Phan doi xung;\n");
					break;
				}
			} else {
				printf("Khong thoa: c. Phan doi xung;\n");
				break;
			}
		}
	}
	/* d. Quan he bac cau */
	for(int i = 0; i < n; i++) {
		int A = a[i].F;
		int B = a[i].S;
		int cnt = 0;
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			if(a[j].F == B) {
				cnt++;
				int C = a[j].S;				
				if(has[A][C]) {
					continue;
				} else {
					printf("Khong thoa: d. Quan he bac cau;\n");
					break;
				}
			} else {
				printf("Khong thoa: d. Quan he bac cau;\n");
				break;
			}
		}
		if(cnt == 0) {
			printf("Khong thoa: d. Quan he bac cau;\n");
			break;
		}
	}
	return 0;
}
