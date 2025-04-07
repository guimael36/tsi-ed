#include <stdio.h>

void duplaCrescente(int a, int b) {
    if (a > b) {
		printf("%d %d\n", b, a);
	} else {
		printf("%d %d\n", a, b);
	}
}

int main() {
    int x, y;
    
    while (1) {
        scanf("%d %d", &x, &y);
        
        if (x == y) {
            break;
        }
        
        duplaCrescente(x, y);
    }
    return 0;
}
