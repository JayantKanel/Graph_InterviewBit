/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 TreeNode* recur(int low,int high,vector<int>&v){
     if(low>high)
       return NULL;
       TreeNode* root=new TreeNode(0);
    //  if(low==high){
    //      root->val=v[low];
    //      return root;
    //  }
     int mid=(high+low)/2;
     root->val=v[mid];
     root->left=recur(low,mid-1,v);
     root->right=recur(mid+1,high,v);
     return root;
 }
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int>v;
    ListNode* l=A;
    while(l!=NULL){
        v.push_back(l->val);
        l=l->next;
    }
    TreeNode* ans=recur(0,v.size()-1,v);
    return ans;
}
