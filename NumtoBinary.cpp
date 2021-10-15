/*Des: return binary 
  Ex: 4 -> 100; 3 -> 011
 */
vector<int> Binary(int k) {
  vector<int> bin;
  int i = 0;
  while (k > 0) {
    bin.push_back(k % 2);
    k /= 2;
    i++;
  }
  reverse(begin(bin), end(bin));
  return bin;
}
