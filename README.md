# Notes

## Bitwise
- a << b = a * (2 ** b)
- “Given a set of numbers where all elements occur an even number of times except one number, find the odd occurring number”
  =>
  int findOdd(int arr[], int n)
{
    int res = 0, i;
    for (i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}
