#include <stdio.h>

int main(void) {
    int i;
    // #region demo
    #define N 10
    int arr[N];
    for (i=0; i<N; i++){
      scanf("%d", &arr[i]);
    }
    for (i=N-1; i>=0; i--){
      printf("%d\n", arr[i]);
    }

    // #endregion demo
    return 0;
}
