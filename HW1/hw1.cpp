//Yilin Yang
//Programming Finance
//HW1

#include <iostream>

//Using several naming shortcuts
using std::cout;
using std::cin;
using std::endl;

int main()
{
	//Initialize number of inputs
	const int input = 5;
	int nums[input];
	
	//Collect inputs from user
	cout<<"Please input "<<input<<" integers:"<<endl;
	for(int i=0; i<input; i++)
	{
		cout<<"Enter integer #"<<i+1<<endl;
		cin>>nums[i];
	}
	
	//Find min of inputs
	cout<<"Calculating min"<<endl;
	int min = nums[0];
	for(int i=0; i<input; i++)
	{
		if(min > nums[i]) min = nums[i];
	}
	cout<<"Min = "<<min<<endl;
	
	//Find max of inputs
	cout<<"Calculating max"<<endl;
	int max = nums[0];
	for(int i=0; i<input; i++)
	{
		if(max < nums[i]) max = nums[i];
	}
	cout<<"Max = "<<max<<endl;
	
	cout<<"Finished"<<endl;
}
