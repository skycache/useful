#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;


class set_maker{
public:
	vector< vector<int> > subset(vector<int>& nums){
		vector< vector<int> > subVector;
		vector<int> tmp;
		nextElement(nums,subVector,tmp,0);
		return subVector;
	}
	void nextElement(vector<int>& nums,vector< vector<int> >& subVector,vector<int> tmp,int curPosi){
		if (curPosi==nums.size()-1){
			subVector.push_back(tmp);
			tmp.push_back(nums[curPosi]);
			subVector.push_back(tmp);
			tmp.pop_back();
			return;
		}
		nextElement(nums,subVector,tmp,curPosi+1);
		tmp.push_back(nums[curPosi]);
		nextElement(nums,subVector,tmp,curPosi+1);
		tmp.pop_back();
		return;
	}
};

int main(){
	int a[]={1,2,3,4,5,6};
	vector<int> nums(a,a+6);
	vector< vector<int> > ans;
	set_maker s;

	ans=s.subset(nums);

	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
