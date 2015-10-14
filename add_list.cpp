#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x){
		val=x;
		next=NULL;
	}
};

class add_list{
public:
	ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
		if(l1==NULL)
			return l2;
		if(l2==NULL)
			return l1;
		int up=0;
		ListNode *pNode,*pNext,*header;
		ListNode *p1,*p2;

		p1=l1;
		p2=l2;
		header=pNode=NULL;

		while(p1!=NULL&&p2!=NULL){
			int cur;
			cur=p1->val+p2->val+up;
			up=cur/10;
			cur=cur%10;
			pNext=new ListNode(cur);

			if(pNode==NULL){
				header=pNode=pNext;
			}
			else{
				pNode->next=pNext;
				pNode=pNext;
			}

			p1=p1->next;
			p2=p2->next;
		}

		if(p1==NULL)
			p1=p2;

		while(p1!=NULL){
			int cur=up+p1->val;
			up=cur/10;
			cur=cur%10;;
			pNext=new ListNode(cur);
			pNode->next=pNext;
			pNode=pNext;
			p1=p1->next;
		}

		if(up){
			pNext=new ListNode(up);
			pNode->next=pNext;
		}

		return header;
	}
};

ListNode* genList(vector<int> a){
	ListNode *pNode,*pNext,*header;
	pNode=NULL;
	header=NULL;
	for(int i=0;i<a.size();i++){
		pNext=new ListNode(a[i]);
		if(pNode==NULL){
			header=pNode=pNext;
		}
		else{
			pNode->next=pNext;
			pNode=pNext;
		}
	}
	return header;
}

void showList(ListNode *header){
	ListNode *p;
	for(p=header;p!=NULL;p=p->next)
		cout<<p->val<<" ";
	cout<<endl;
	return;
}


int main(){
	int a[]={1};
	int b[]={9,9,9,9};
	vector<int> va(a,a+sizeof(a)/sizeof(int));
	vector<int> vb(b,b+sizeof(b)/sizeof(int));

	ListNode *la,*lb;
	la=genList(va);
	lb=genList(vb);

	add_list ad;
	ListNode *ans;
	ans=ad.addTwoNumbers(la,lb);
	showList(ans);

	return 0;
}
