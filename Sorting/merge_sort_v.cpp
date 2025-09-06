//merge sort.
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&v,int l,int mid, int r) {
	int n = v.size();
	int n1 = mid+1-l;
	int n2 = r-mid;
	vector<int> a(n1);
	vector<int> b(n2);

	for(int i=0 ; i<n1 ; i++) {
		a[i] = v[l+i];
	}

	for(int j=0 ; j<n2 ; j++) {
		b[j] = v[mid+1+j];
	}

	int i=0;
	int j=0;
	int k=l;
	while(i<n1 && j<n2) {
		if(a[i] < b[j]) {
			v[k] = a[i];
			i++;
			k++;
		}
		else {
			v[k] = b[j];
			j++;
			k++;
		}
	}

		//for the leftovers.
		while(i<n1) {
				v[k] = a[i];
				i++;
				k++;
		}
		while(j<n2) {
			    v[k] = b[j];
				j++;
				k++;
		}


}
void mergesort(vector<int>&v,int l,int r) {
	if(l<r) {

		int mid = l + (r - l) / 2;

		mergesort(v,l,mid);
		mergesort(v,mid+1,r);
		merge(v,l,mid,r);

	}

}

int main() {
	vector<int> v = {1,21,53,77,12,34};
	int n = v.size();

	mergesort(v,0,n-1);

	cout<<"ARRAY SORTED SUCCESSFULLY.";

	for(int i=0 ; i<n; i++) {
		cout<<v[i]<<" ";
	}
	return 0;
}