// Logic:
//We know that for every number if the difference between there adjacent digit is one then the number is stepping number
//We will use that to our advantage
//every number from 0-9 will be stepping number obviously:)
//Now what we will do is for every number we will insert digit with difference 1 with end digit of curr number at the end
//Lets take an example if number is 12
// we can 1 or 3 at the end
//so numbers will be after inserting are 121 and 123
//Now lets take care of some base cases
//if last digit is 9 we can only add 8 to it(789 then 7898 , 7890 is not step number)
//Same goes for zero as well
//we will push all the number from 0-9 in queue we will keep created step number from this number and push it to the queue
//if number is less then the maximum no. that is B in here
vector<int> Solution::stepnum(int A, int B) {
    queue<int>q;
    for(int i=0;i<=9;i++){
        q.push(i);
    }
    vector<int>ans;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        if(curr>=A && curr<=B)
          ans.push_back(curr);
        if(curr==0)
         continue;
        int last=curr%10;
        int l1,l2;
        if(last==0){
            int temp=curr*10+1;
            if(temp<=B)
              q.push(temp);
        }
        else if(last==9){
            // int temp=curr*10;
            // if(temp<=B)
            //   q.push(temp);
           int temp=curr*10+last-1;
            if(temp<=B)
              q.push(temp);
        }
        else{
            int temp=curr*10+last+1;
            if(temp<=B)
              q.push(temp);
            temp=curr*10+last-1;
            if(temp<=B)
              q.push(temp);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
