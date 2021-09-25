int recur(int n,int index,vector<int>&fib){
    if(n==0)
       return 0;
    if(fib[index]>n)
      return recur(n,index-1,fib);
    
    return 1+recur(n-fib[index],index-1,fib);

}
int Solution::fibsum(int A) {
    int a=1;
    int b=1;
    if(A==1)
      return 1;
  if(A==2)
    return 1;
    int cnt=2,sum=2;
    vector<int>fib;
    fib.push_back(1);
    fib.push_back(1);
  while(a<A){
      int c=a+b;
      b=a;
      a=c;
      fib.push_back(a);
  }
  return recur(A,fib.size()-1,fib);
}
