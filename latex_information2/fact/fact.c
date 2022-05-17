int fact(int x) {
    int sum = 0;
    if (x >= 0) {
        sum = 1;
        for (int i = 1; i < x + 1; i++) {
            sum *= i;
        }
    }

    else {
        sum = 1;
        for (int i = -1; i > x - 1; i--) {
            sum *= i;
        }
    }
    return sum;
}