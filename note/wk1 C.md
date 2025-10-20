#C   
# Note  
Header files: 头文件,其中包含你需要调用的函数.  

# Problem Set 1  
## Credit  
信用卡卡号长度:  
American Express: 15-digit numbers  
MasterCard: 16-digit numbers  
Visa: 13- and 16-digit numbers  

信用卡卡号开头数字:  
American Express: 34 or 37  
MasterCard: 51, 52, 53, 54, or 55  
Visa: 4  

Luhn 算法:  
1. 从倒数第二位开始,隔一位算一次,每一位上的数字都乘2,得到一串数字,把这一串数字每一位都相加,得到数字A.
2. 再把那些第一步中没被乘2的位上的数字写成一串,把它们与数字A相加,得到数字B.
3. 如果数字B被10整除,即尾数为0,则通过检验.

判断信用卡卡号长度及开头数字,如果合法则检验其有效性,如果有效则输出其对应的信用卡公司.  
注意:  
如果输入非卡号的数字,输出INVALID.  