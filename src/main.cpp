#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:

    int leftC{-1},rightC{-1};

public:
    
    static string stringInvert(string s){
        string s2{""};
        for(auto c : s){
            s2.insert(0,1,c);
        }
        return s2;
    }
    
    // not working
    static void searchMaxLenPalimSubstr(string s,string& maxFoundStr){
        string s2{""};
        if(s.empty())
            return;
        
        for(auto c : s){
            s2 += c;
            if(s2==stringInvert(s2)){
                if(s2.length()>maxFoundStr.length()){
                    maxFoundStr = s2;
                }
            }
        }

        string s3=s;
        s3.erase(0,1);
        searchMaxLenPalimSubstr(s3,maxFoundStr);
        string s4=s;
        s4.erase(s4.length()-1,1);
        searchMaxLenPalimSubstr(s4,maxFoundStr);

         /*if(!s.empty()){
                    s.erase(0,1);
                    searchMaxLenPalimSubstr(s,maxFoundStr);
                }*/
    }

    void expandAroundCenter(string s,int left,int right){
        int len=s.length();

        while(left>=0 && right<len && s[left]==s[right]){
            left--;
            right++;
        }
        left++;
        right--;

        if(rightC == -1 || (right-left+1 > rightC - leftC + 1))
        {
            rightC = right;
            leftC = left;
        }
    }

    string longestPalindrome(string s) {
        if(s.empty() || s.length()<1) return "";
        
        int len = s.length();
        int start{0},end{0};

        for (int sIndex = 0; sIndex < len; sIndex++)
        {
            expandAroundCenter(s,sIndex,sIndex);
            expandAroundCenter(s,sIndex-1,sIndex);
        }
    
        string palindrome = "";
        if(rightC != -1) palindrome = s.substr(leftC,rightC-leftC+1);
        return palindrome;   
    }
};

int main() {
    Solution sol;
    string s2{"cbcbaaabaaacbcb"};
    string s{"civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"};
    //std::cout << Solution::stringInvert(s) << std::endl;
    //s.erase(0,1);
    std::cout << sol.longestPalindrome(s) << std::endl;

    getchar();
}