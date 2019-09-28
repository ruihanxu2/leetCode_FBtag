#include <iostream>
#include <string>
#include <stack>

using namespace std;
string trim(string s, int num){
	if(s.size() < num){
		return s;
	}
	stack<string> tags;
	int len = 0; // record the length to make valid
	int i;
	int validPos = 0;
	for(i = 0; i < s.size(); i++){
		if(i + len >= num) break;
		// cur pos must be valid
		validPos = i;
		
		// parse
		if(s[i] == '<'){
			// a tag
			int j = i;
			while(s[i]!='>'){
				i++;
			}
			string curTag = s.substr(j, i - j + 1);
			if(curTag[1] == '/'){
				//close tag
				tags.pop();
				len -= curTag.size();
			}
			else{
				//opentag
				tags.emplace(curTag);
				len += curTag.size() + 1;
			}
		}
		else{
			// a char, do nothing
		}
	}
	if(i + len > num){
		if(!tags.empty()) tags.pop();
		i = validPos;
	}
	string res = s.substr(0, i);
	while(!tags.empty()){
		string cur = tags.top();
		tags.pop();
		res += cur.substr(0, 1) + "/" + cur.substr(1);
	}
	return res;
	
}
int main(){
	string i1 = "<p>I am grajbkjkjjjjjjjjjjjjhkjhkjkhkjhd </p>";
	string i2 = "<p><h1>I am grajbkjkjjjjjjjjjjjjhkdk</h1></p>";
	string i3 = "<p><h1><h2>jbkjkjjjjjjjjjjjjhkjhkjkh</h2></h1></p>";
	string i4 = "<p><h1><h2>jbkh</h2></h1></p>";
	string i5 = "<p>hd</p>";
	string i6 = "<p>d </p>";
	string i7 = "<p>I</p><h1>jjjjjjh</h1>jkhkjhd</p> </p>";
	string i8 = "<p>335</p>";
	string i9 = "<p>I am grajbkjkjjjjjjjjjjjjhkjhkjkhkjhd </p>";
	string i0 = "<p>I am grajbkjkjjjjjjjjjjjjhkjhkjkhkjhd </p>";
		
	string r1 = trim(i1, 20);
	string r2 = trim(i2, 20);
	string r3 = trim(i3, 20);
	string r4 = trim(i4, 20);
	string r5 = trim(i5, 20);
	string r6 = trim(i6, 2);
	string r7 = trim(i7, 20);
	string r8 = trim(i8, 10);
	string r9 = trim(i9, 20);
	string r0 = trim(i0, 20);

	cout<<r1<<endl;
	cout<<r2<<endl;
	cout<<r3<<endl;
	cout<<r4<<endl;
	cout<<r5<<endl;
	cout<<r6<<endl;
	cout<<r7<<endl;
	cout<<r8<<endl;
	cout<<r9<<endl;
	cout<<r0<<endl;
	return 0;
}
/* 
<p> abcd </p>
  |	   |   |


*/

/*

string trim(string input, int num) {
	if (input.size() <= num)
		return input;

	stack<string> st;
	int len = 0; // the length to be added
	string res;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '<') { // a tag
			int l = i;
			while (i < input.size() && input[i] != '>') {
				i++;
			}
			res += input.substr(l, i - l + 1);
			if (input[l + 1] == '/') { // right tag
				string temp = st.top(); 
				st.pop(); 
				len -= temp.length() + 1;
			} 
			else {   // left tag
				st.push(input.substr(l, i - l + 1));
				len += i - l + 1 + 1;
				if (len + res.length() >= num) {
					// trim the previous left tag
					res = res.substr(0, l);
					st.pop();
					break;
				} 
			}
		} 
		else { // a character
			res += input[i];
			if (res.length() + len == num) {
				break;
			}
		}
	}
	
	while (!st.empty()) {
		string right = st.top();
		st.pop();
		right = right[0] + "/" + right.substr(1);
		res += right;
	}
	
	return res; 
}*/