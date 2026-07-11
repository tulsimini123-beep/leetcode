int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    long long result = 0;

    // Skip leading spaces
    while (s[i] == ' ') {
        i++;
    }

    // Check sign
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // Read digits
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        // Check overflow before updating result
        if (sign == 1 && (result > (INT_MAX - digit) / 10))
            return INT_MAX;

        if (sign == -1 && (result > ((long long)INT_MAX + 1 - digit) / 10))
            return INT_MIN;

        result = result * 10 + digit;
        i++;
    }

    return (int)(sign * result);
}