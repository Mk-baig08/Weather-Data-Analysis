/*Background: You are working on a program to analyze weather data for a city. The data is collected
daily for a month, and you need to store and process it.
Task:
1. Ask the user to input the number of days in the month (e.g., 28, 30, or 31).
2. Dynamically allocate a 2D array to store the temperature data for each day (rows = days, columns = 3
   for min, max, and average temperature).
3. Populate the array with user-provided temperature data.
4. Perform the following analysis:
• Find the hottest and coldest day of the month.
• Calculate the monthly average temperature.
• Display the temperature trends (e.g.days with increasing max temperature).
5. Deallocate the memory after use*/

#include<iostream>
#include<iomanip>
#include<new>

using namespace std;

int main()
{
	int i,j,rows;
	int columns=3;
	int hottest=INT_MIN;
	int coldest=INT_MAX;
	double monthly_avg,avg;
	double sum=0;
	char month;
	
    // 1) Input no. of days
	cout<<"\nEnter no. of days in the month: ";
	cin>>rows;
	cout<<"---------------------------------\n";
	double **temp;  //pointer-to-pointer
	temp=new double *[rows];  //Dynamically allocation of pointer array(rows)
	
	// 2) Dynamic allocation of 2D array(columns)
	for(i=0;i<rows;i++)
	{
		temp[i]=new double[columns];  
	}
	
	// 3) Input data (Populate array)
	for(i=0;i<rows;i++)
	{
		cout<<"\n Enter temperature data for Day "<<i+1<<": \n";
		cout<<"\nMinimum temperature: ";
		cin>>temp[i][0];
		cout<<"\nMaximum temperature: ";
		cin>>temp[i][1];
		avg=(temp[i][0]+temp[i][1])/2;
		temp[i][2]=avg;
		sum+=temp[i][2];
		monthly_avg=sum/rows;
		cout<<"\nAverage temperature: "<<avg;
		cout<<"\n-----------------------------\n";
	}
	// 4) Weather Analysis: 
	
	// i) Hottest day of month
	int loc;
	for(i=0;i<rows;i++)
	{
		if(temp[i][1]>hottest)
	    {
		    hottest=temp[i][1];
		    loc=i+1;
	    }
	}
	cout<<"\n|Hottest day of month: "<<"Day "<<loc<<" |";
	cout<<"\n--------------------------------\n";
	
	// ii) Coldest day of month
	for(i=0;i<rows;i++)
	{
		if(temp[i][0]<coldest)
	    {
		    coldest=temp[i][1];
		    loc=i+1;   
	    }
	}
	cout<<"\n|Coldest day of month: "<<"Day "<<loc<<" |";
	cout<<"\n--------------------------------\n";
	
	// iii) Monthly Average Temperature
	cout<<"\n|Average temperature of Month: "<<monthly_avg<<"|";
	cout<<"\n--------------------------------------\n";
	
	// iv) Temperature Trends (days with increasing max&min temp)
	cout<<"\n\n\t------*Temperature Trends------*\n";
	cout<<"\nIncreasing Trend:\n";
	cout<<"-----------------\n";
	for(i=1;i<rows;i++)
	{
		if(temp[i][1]>temp[i-1][1])
		{
			cout<<"\nDay "<<i+1<<" (Max temp): "<<temp[i][1]<<" > Day "<<i<<" (Max temp): "<<temp[i-1][1]<<endl;
		}
	}
	cout<<"\nDecreasing Trend:\n";
	cout<<"-----------------\n";
	for(i=1;i<rows;i++)
	{
		if(temp[i][0]<temp[i-1][0])
		{
			cout<<"\nDay "<<i+1<<" (Min temp): "<<temp[i][0]<<" < Day "<<i<<" (Min temp): "<<temp[i-1][0]<<endl;
		}
	}
	
	// 5) Deallocation of memory:
	for(i=0;i<rows;i++)
	{
		delete [] temp[i];
	}
	
	delete [] temp;
	
	
	return 0;
}