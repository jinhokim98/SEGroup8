#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

ifstream inputFile (INPUT_FILE_NAME);   // input.txt �� �б���� ����
ofstream outputFile (OUTPUT_FILE_NAME); // output.txt �� ������� ����

/*
Class: SignUp
Description: ȸ������ ��Ʈ�� Ŭ�����̴�.
Created: 2022/5/26 6:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class SignUp
{
private:
    
public:
    SignUp();
    void ProceedSignUp();
    void getEssentailInfo(string input_memberName, string input_idCardNumber, string input_id, string input_pw);
};

/*
Class: SignUpUI
Description: ȸ������ �ٿ���� Ŭ�����̴�.
Created: 2022/5/26 6:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class SignUpUI
{
private:
    
public:
    void PushSignUpButton(SignUp *signUp);
    void ShowEssentialInfoInputInterface();
    void InputEssentialInfo(SignUp *signUp);
    void ShowCompleteSignUpMessage(string memberName, string memberIDCardNumber, string memberID, string memberPW);
};

/*
Class: DeleteMyAccount
Description: ȸ��Ż�� ��Ʈ�� Ŭ�����̴�.
Created: 2022/5/26 6:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class DeleteMyAccount
{
private:
    
public:
    DeleteMyAccount();
    void DeleteAccount();

};

/*
Class: DeleteMyAccountUI
Description: ȸ��Ż�� �ٿ���� Ŭ�����̴�.
Created: 2022/5/26 6:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class DeleteMyAccountUI
{
private:
    
public:
    void DeleteAccountButton(DeleteMyAccount *deleteMyAccount);
    void ShowCompleteDeleteAccount(string id);
};

/*
Class: Login
Description: �α��� ��Ʈ�� Ŭ���� �̴�.
Created: 2022/5/26 3:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class Login
{
private:
    
public:
    Login();
    bool IDPWinputed(string input_id, string input_pw);
};

/*
Class: LoginUI
Description: �α��� �ٿ���� Ŭ�����̴�.
Created: 2022/5/26 3:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class LoginUI
{
private:
    
public:
    bool inputIDPW(Login* login);
    void ShowCompleteLoginMessage(string curLoginMemberID, string curLoginMemberPW);
};

/*
Class: Logout
Description: �α׾ƿ� ��Ʈ�� Ŭ�����̴�.
Created: 2022/5/26 3:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class Logout
{
private:
    
public:
    Logout();
    void DoLogout();
};

/*
Class: LogoutUI
Description: �α׾ƿ� �ٿ���� Ŭ�����̴�.
Created: 2022/5/26 3:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class LogoutUI
{
private:
    
public:
    void PushLogoutButton(Logout *logout);
    void ShowCompleteLogoutMessage();
};

/*
Class: Member
Description: ȸ�� ��ƼƼ Ŭ�����̴�.
Created: 2022/5/25 5:00 am
Author: ���ؼ�
mail: cys4439@naver.com
*/
class Member
{
private:
    string id, pw, memberName, idCardNumber;

public:
	string getID(){return id;}  // ��ü�� id�� get�ϴ� �Լ�
	string getPW(){return pw;}  // ��ü�� pw�� get�ϴ� �Լ�
	string getMemberName(){return memberName;}  // ��ü�� �̸��� get�ϴ� �Լ�
	string getIDCardNumber(){return idCardNumber;}  // ��ü�� �ֹι�ȣ�� get�ϴ� �Լ�
	Member* address_of_object(){return this;}   // �� ��ü�� �ּҸ� get�ϴ� �Լ�
    int checkIDPW(string input_id,string input_pw); // �Է¹��� id, pw�� ��Ī�Ǵ��� Ȯ���ϴ� �Լ�

	Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber); //������
	~Member(); //�ı���
};

vector < tuple<string, string, Member*> > MemberLoginInfo; //������ ù���� id , �ι�° ���� pw , ����° ���� Member��ü�� �ּҸ�����Ű�� ������ ������ ����
Member* curLoginMember; // ���� �α������� ȸ���� ������ �������� ����
bool loginState = false; // ���� �α������̸� true �α׾ƿ����̸� false ������ �������� ����

/*
Function : Member::Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber)
Description: �� �Լ��� Member Ŭ������ ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters :
string input_id - �Էµ� id
string input_pw - �Էµ� pw
string input_memberName - �Էµ� ȸ���� �̸�
string input_idCardNumber - �Էµ� �ֹι�ȣ
Return Value : ����
Created: 2022/5/25 5:00 am
Author: ���ؼ�
*/
Member::Member(string input_id, string input_pw, string input_memberName, string input_idCardNumber)
{
	id = input_id;
	pw = input_pw;
	memberName = input_memberName;
	idCardNumber = input_idCardNumber;

    MemberLoginInfo.push_back({this->getID(), this->getPW(), this->address_of_object()}); // �Էµ� ȸ���� ������ MemberLoginInfo�� Ǫ���Ѵ�.
}

/*
Function : Member::~Member()
Description: �� �Լ��� Member Ŭ������ ��ü�� �ı��ϴ� �ı��� �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/25 5:00 am
Author: ���ؼ�
*/
Member::~Member()
{
    for (int i=0; i<MemberLoginInfo.size(); i++)
    {
        string id = get<0>(MemberLoginInfo[i]);
        string pw = get<1>(MemberLoginInfo[i]);
        Member *pointer_Of_Address = get<2>(MemberLoginInfo[i]);
        // MemberLoginInfo ���Ϳ� ����ִ� �� ��ü�� id, pw, ��ü�� �ּ� ������


        string id_Of_CurObject = this->getID(); // ���� ����� ��ü�� id
        string pw_Of_CurObject = this->getPW(); // ���� ����� ��ü�� pw
        Member *pointer_Of_CurObject = this->address_of_object(); // ���� ����� ��ü�� �ּ� ������

        if (id_Of_CurObject == id && pw_Of_CurObject == pw && pointer_Of_CurObject == pointer_Of_Address) // ���� ����� �������ִ� ������ MemberLoginInfo�κ��� �����.
        {
            MemberLoginInfo.erase(MemberLoginInfo.begin() + i);
            break;
        }
    }
}

/*
Function : bool LoginUI::inputIDPW(Login* login)
Description: �� �Լ��� �α��ν� id�� pw�� �Է��ϴ� �Լ��Դϴ�.
Parameters : Login* login - �α��� Ŭ������ ��ü�� �ּҸ� ����Ű�� ������
Return Value : bool
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
bool LoginUI::inputIDPW(Login* login)
{
    string input_id, input_pw;
    inputFile>>input_id>>input_pw;    // UI�� id, pw �Է�

    return login->IDPWinputed(input_id,input_pw);   //��Ʈ�� Ŭ�������� �Է��� id, pw ����
}

/*
Function : void LoginUI::ShowCompleteLoginMessage(string curLoginMemberID, string curLoginMemberPW)
Description: �� �Լ��� �α��� �Ϸ�� �α��� �� ȸ���� id�� pw�� ����ϴ� �Լ��Դϴ�.
Parameters :
string curLoginMemberID - �α��� �� ȸ���� id
string curLoginMemberPW - �α��� �� ȸ���� pw
Return Value : void
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
void LoginUI::ShowCompleteLoginMessage(string curLoginMemberID, string curLoginMemberPW)
{
    //�α����� �Ϸ�Ǿ��ٴ� â�� ���� �ڵ� (�̹����������� �α����� ȸ���� ���̵� ��й�ȣ�� �ؽ�Ʈ�� ���)
    outputFile<<"> "<<curLoginMemberID<<" "<<curLoginMemberPW<<endl<<endl;
}

/*
Function : Login::Login()
Description: �� �Լ��� Login Ŭ������ ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
Login::Login()
{   
    LoginUI *loginUI = new LoginUI;

    if (loginUI->inputIDPW(this))   // id pw�� �Է��Ѵ�. �α����� �����ϸ� (�Է��� id�� �Է��� pw�� ��Ī�� �´°��) �α��� �Ѵ�.
    {
        loginState=true;
        loginUI->ShowCompleteLoginMessage(curLoginMember->getID(), curLoginMember->getPW());
    }
    else    // �α����� �Ұ����ϸ� (�Է��� id�� �Է��� pw�� ��Ī�� �ƴѰ��) �α��� ���� ���ϰ� �Ѵ�.
    {
        outputFile<<"ȸ�� ������ ���ų� id�� pw�� ��Ī�� �����ʽ��ϴ�. �α��� ����"<<endl<<endl;  // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
    }
}

/*
Function : bool Login::IDPWinputed(string input_id, string input_pw)
Description: �� �Լ��� UI�κ��� �Է¹��� id, pw�� ��Ʈ�� Ŭ������ �����ϴ� �Լ��Դϴ�.
Parameters :
string input_id - �Էµ� id
string input_pw - �Էµ� pw
Return Value : bool
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
bool Login::IDPWinputed(string input_id, string input_pw)
{
    if (curLoginMember->checkIDPW(input_id,input_pw)!=-1) // id�� pw�� ��Ī�Ǹ�
    {
        curLoginMember=get<2>(MemberLoginInfo[curLoginMember->checkIDPW(input_id, input_pw)]); // ��Ī�� id,pw�� ȸ������ ���� �α������� ȸ���� ������ ������
        return true;    // �α��� �����ϹǷ� true ��ȯ
    }
    return false;   // �α��� �Ұ����ϸ� false ��ȯ
}

/*
Function : int Member::checkIDPW(string input_id,string input_pw)
Description: �� �Լ��� �α����Ҷ� �Է¹��� id�� pw�� ���� ��Ī�� �Ǵ��� Ȯ���ϴ� �Լ��Դϴ�.
Parameters :
string input_id - �Էµ� id
string input_pw - �Էµ� pw
Return Value : int
Created: 2022/5/25 5:00 am
Author: ���ؼ�
*/
int Member::checkIDPW(string input_id,string input_pw)
{
    for (int i=0; i<MemberLoginInfo.size(); i++)
    {
        string id=get<0>(MemberLoginInfo[i]);
        string pw=get<1>(MemberLoginInfo[i]);
        if (id == input_id && pw == input_pw) // �Է��� id�� pw�� ��Ī �Ǹ�
        {
            return i; // �ε��� ��ȯ
        }
    }
    return -1; // ��Ī�� �Ǵ°��� ������ -1��ȯ
}

/*
Function : LogoutUI::PushLogoutButton(Logout *logout)
Description: �� �Լ��� �α׾ƿ� ��ư�� ������ �α׾ƿ��� �����ϴ� �Լ��Դϴ�.
Parameters : Logout *logout - Logout ��ü�� �ּҸ� ����Ű�� ������
Return Value : void
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
void LogoutUI::PushLogoutButton(Logout *logout)
{
    if (loginState)  // �α��� ���¿����� �α׾ƿ� �� �� �ִ�.
    {
        logout->DoLogout();
    }
    else
    {
        outputFile<<"�α��� ���¿��� �α׾ƿ� ���ּ���"<<endl<<endl;  // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
        return;
    }
}

/*
Function : void LogoutUI::ShowCompleteLogoutMessage()
Description: �� �Լ��� �α׾ƿ��� �Ϸ������� �α׾ƿ��� ȸ���� id�� ����ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
void LogoutUI::ShowCompleteLogoutMessage()
{
    //�α׾ƿ��� �Ϸ�Ǿ��ٴ� â�� ���� �ڵ� (�̹����������� �α׾ƿ��� ȸ���� ���̵� �ؽ�Ʈ�� ���)
    outputFile<<"> "<<curLoginMember->getID()<<endl<<endl;
}

/*
Function : Logout::Logout()
Description: �� �Լ��� Logout ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
Logout::Logout()
{
    LogoutUI *logoutUI = new LogoutUI(); logoutUI->PushLogoutButton(this);
}

/*
Function : void Logout::DoLogout()
Description: �� �Լ��� �α׾ƿ��۾��� ������ �����ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/26 3:00 am
Author: ���ؼ�
*/
void Logout::DoLogout()
{
    LogoutUI *logoutUI = new LogoutUI;
    logoutUI->ShowCompleteLogoutMessage();
    curLoginMember=NULL;
    loginState=false;
}

/*
Function : void SignUpUI::PushSignUpButton(SignUp *signUp)
Description: �� �Լ��� ȸ������ ��ư ������ ȸ�������� �����ϴ� �Լ��Դϴ�.
Parameters : SignUp *signUp - SignUp Ŭ���� ��ü�� ������
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUpUI::PushSignUpButton(SignUp *signUp)
{
    signUp->ProceedSignUp();
}

/*
Function : void SignUpUI::InputEssentialInfo(SignUp *signUp)
Description: �� �Լ��� ȸ���� �⺻����(id, pw, ȸ���̸�, ȸ���ֹι�ȣ)�� �Է��ϴ� �Լ��Դϴ�.
Parameters : SignUp *signUp - SignUp Ŭ���� ��ü�� ������
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUpUI::InputEssentialInfo(SignUp *signUp)
{
    string input_id, input_pw, input_memberName, input_idCardNumber;
    inputFile>>input_memberName>>input_idCardNumber>>input_id>>input_pw;  // ȸ���� �⺻�����Է�

    signUp->getEssentailInfo(input_memberName, input_idCardNumber, input_id, input_pw); // ȸ���� �⺻ ������ ��Ʈ�� Ŭ������ �ѱ�
}

/*
Function : void SignUpUI::ShowEssentialInfoInputInterface()
Description: �� �Լ��� ȸ���� �⺻������ �Է��ϴ� �������̽��� ȸ������ �����ִ� �Լ��Դϴ�
Parameters : void
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUpUI::ShowEssentialInfoInputInterface()
{
    /*
    ȸ���� �⺻������ �Է��ϴ� â���� �̵��ϴ� �ڵ� ����(�̹����������� �ؽ�Ʈ�� ǥ�� �ϹǷ� �ڵ� ����)
    */
}

/*
Function : void SignUpUI::ShowCompleteSignUpMessage(string memberName, string memberIDCardNumber, string memberID, string memberPW)
Description: �� �Լ��� ȸ�������� �Ϸ��������� ȸ���� �̸�, ȸ���� �ֹι�ȣ, ȸ���� id, ȸ���� pw�� ����ϴ� �Լ��Դϴ�.
Parameters :
string memberName - ȸ���� �̸�
string memberIDCardNumber - ȸ���� �ֹι�ȣ
string memberID - ȸ���� id
string memberPW - ȸ���� pw
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUpUI::ShowCompleteSignUpMessage(string memberName, string memberIDCardNumber, string memberID, string memberPW)
{
    // ȸ������ �Ϸ��ߴٴ� �޼��� ���� ���Ŀ� �°� ���
    outputFile<<"> "<<memberName<<" "<<memberIDCardNumber<<" "<<memberID<<" "<<memberPW<<endl<<endl;
}

/*
Function : SignUp::SignUp()
Description: �� �Լ��� SignUp ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters : void
Return Value : ����
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
SignUp::SignUp()
{
    SignUpUI *signUpUI = new SignUpUI;
    signUpUI->PushSignUpButton(this);
    signUpUI->InputEssentialInfo(this);
}

/*
Function : void SignUp::ProceedSignUp()
Description: �� �Լ��� ȸ�������� ����ؼ� �����ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUp::ProceedSignUp()
{
    SignUpUI *signUpUI = new SignUpUI;
    signUpUI->ShowEssentialInfoInputInterface();
}

/*
Function : void SignUp::getEssentailInfo(string input_memberName, string input_idCardNumber, string input_id, string input_pw)
Description: �� �Լ��� �Է¹��� ȸ�����̸�, �ֹι�ȣ, �Էµ� id, �Էµ� pw ������ get�Ͽ� ȸ������ �۾��� ������ �����ϴ� �Լ��Դϴ�.
Parameters :
string input_memberName - �Է¹��� ȸ���� �̸�
string input_idCardNumber - �Է¹��� ȸ���� �ֹι�ȣ
string input_id - �Է¹��� ȸ���� id
string input_pw - �Է¹��� ȸ���� pw
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void SignUp::getEssentailInfo(string input_memberName, string input_idCardNumber, string input_id, string input_pw)
{
    bool signupPossible = true; //ȸ������ �����ϸ� true �ƴϸ� false

    for (int i=0; i<MemberLoginInfo.size(); i++)
    {
        string id=get<0>(MemberLoginInfo[i]);

        if (id==input_id)    // ���Ϳ� �Է��� id�� �����ϸ� id �ߺ��� �ȵǹǷ�
        {
            signupPossible = false; // ������ �Ұ����ϴ�.
        }
    }
    
    if (signupPossible)  // ȸ�������� �����ϸ� (=��ġ�� ���̵������) ȸ�������Ѵ�.
    {
        Member* m = new Member(input_id, input_pw, input_memberName, input_idCardNumber);

        SignUpUI* signUpUI = new SignUpUI;
        signUpUI->ShowCompleteSignUpMessage(input_memberName, input_idCardNumber, input_id, input_pw);
    }
    else // ȸ�������� �Ұ����ϸ� (=��ġ�� ���̵�������) ȸ������ ���ϰ��Ѵ�.
    {
        outputFile<<"���̵� ���ļ� ȸ�������� �Ұ��� �մϴ�"<<endl<<endl;   // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
    }
}

/*
Function : void DeleteMyAccountUI::DeleteAccountButton(DeleteMyAccount *deleteMyAccount)
Description: �� �Լ��� ȸ��Ż�� ��ư�� ������ ȸ��Ż�� �����ϴ� �Լ��Դϴ�.
Parameters : DeleteMyAccount *deleteMyAccount - DeleteMyAccount Ŭ������ ��ü�� �ּҸ� ����Ű�� ������
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void DeleteMyAccountUI::DeleteAccountButton(DeleteMyAccount *deleteMyAccount)
{
    deleteMyAccount->DeleteAccount();
}

/*
Function : void DeleteMyAccountUI::ShowCompleteDeleteAccount(string curMemberID)
Description: �� �Լ��� ȸ��Ż�� �Ϸ� ������ Ż���� ȸ���� id�� ����ϴ� �ռ��Դϴ�.
Parameters : string curMemberID - Ż���� ȸ���� id
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void DeleteMyAccountUI::ShowCompleteDeleteAccount(string curMemberID)
{
    //ȸ��Ż�� �Ϸ�Ǿ��ٴ� â�� ���� �ڵ� (�̹����������� ȸ��Ż���� ȸ���� ���̵� �ؽ�Ʈ�� ���)
    outputFile<<"> "<<curMemberID<<endl<<endl;
}

/*
Function : DeleteMyAccount::DeleteMyAccount()
Description: �� �Լ��� DeleteMyAccount Ŭ������ ��ü�� �����ϴ� ������ �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
DeleteMyAccount::DeleteMyAccount()
{
    DeleteMyAccountUI *deleteMyAccountUI = new DeleteMyAccountUI;
    deleteMyAccountUI->DeleteAccountButton(this);
}

/*
Function : DeleteMyAccount::DeleteAccount()
Description: �� �Լ��� ȸ��Ż�� �۾��� ������ �����ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/26 6:00 am
Author: ���ؼ�
*/
void DeleteMyAccount::DeleteAccount()
{
    if (loginState)  // ���� �α��� ���϶��� ȸ�� Ż�� �����ϴ�.
    {
        DeleteMyAccountUI *deleteMyAccountUI = new DeleteMyAccountUI;
        string curMemberID = curLoginMember->getID();   // Ż���ϴ� ȸ���� ���̵� ����
        curLoginMember->~Member(); // ��ü �����Ѵ�.
        deleteMyAccountUI->ShowCompleteDeleteAccount(curMemberID); //UI�� ȸ�� Ż�� �Ǿ��ٴ� â�� ����
        curLoginMember=NULL; // ���� �α������� ȸ�� ����.
        loginState=false; // �α׾ƿ����·� �����.
    }
    else    // �α׾ƿ� ���¿��� ȸ��Ż�� �ϴ°��� �ȵȴ�.
    {
        outputFile<<"�α����� ������ �Ŀ� ȸ��Ż�� ���ּ���"<<endl<<endl;   // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
    }
}

/*
Function : void doTask()
Description: �� �Լ��� �Է¹��� �޴��� ���� �ش� �޴��� �۾��� �ϴ� �Լ��Դϴ�.
Parameters : void
Return Value : void
Created: 2022/5/25 : 3:00 pm
Author: ���ؼ�
*/
void doTask(){
    if (inputFile.is_open())    //������ �����ִ��� Ȯ��
    {
        while (!inputFile.eof())    //������ ������ �д°��� �ݺ�
        {
            string str;

            while (1)
            {
                int menu1,menu2;
                inputFile>>menu1>>menu2;    // ���Ϸκ��� �޴�2�� �� �Է¹���

                if (menu1 == 1 && menu2 == 1)
                {
                    outputFile<<"1.1. ȸ������"<<endl;

                    if (loginState)  // ���� �α������̶�� ȸ�������� �� �� ����.
                    {
                        outputFile<<"�α׾ƿ� �� ȸ�������� �������ּ���"<<endl<<endl;    // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
                    }
                    else    // �α׾ƿ� ���¿����� ȸ�������� �� �� �ִ�.
                    {
                        SignUp *signUp = new SignUp;
                    }
                }
                else if (menu1 == 1 && menu2 == 2)
                {
                    outputFile<<"1.2. ȸ��Ż��"<<endl;

                    DeleteMyAccount *deleteMyAccount = new DeleteMyAccount;
                }
                else if (menu1 == 2 && menu2 == 1)
                {
                    outputFile<<"2.1. �α���"<<endl;

                    if (loginState)  // �α��� ���¿����� �α����� �� �� ����.
                    {
                        outputFile<<"�α��� �� �������ϴ� �α׾ƿ� �� ������ּ���"<<endl<<endl;  // ����׽� Ȯ���ϱ����� ����ó�� ���������� ������ �Ǵ��ڵ�
                    }
                    else // �α׾ƿ� ���¿����� �α��� �� �� �ִ�.
                    {
                        Login *login = new Login;
                    }
                }
                else if (menu1 == 2 && menu2 == 2)
                {
                    outputFile<<"2.2. �α׾ƿ�"<<endl;

                    Logout *logout = new Logout;

                }
                else if (menu1 == 3 && menu2 == 1)
                {
                    outputFile<<"3.1. �Ǹ� �Ƿ� ���"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 3 && menu2 == 2)
                {
                    outputFile<<"3.2. ��� ��ǰ ��ȸ"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 3 && menu2 == 3)
                {
                    outputFile<<"3.3. �Ǹ� �Ϸ� ��ǰ ��ȸ"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 4 && menu2 == 1)
                {
                    outputFile<<"4.1. ��ǰ ���� �˻�"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 4 && menu2 == 2)
                {
                    outputFile<<"4.2. ��ǰ ����"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 4 && menu2 == 3)
                {
                    outputFile<<"4.3. ��ǰ ���� ���� ��ȸ"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 4 && menu2 == 4)
                {
                    outputFile<<"4.4. ��ǰ ���Ÿ����� ��"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 5 && menu2 == 1)
                {
                    outputFile<<"5.1. �Ǹ� ��ǰ ���"<<endl;
                    /*
                        ������
                    */
                    outputFile<<endl<<endl;
                }
                else if (menu1 == 6 && menu2 ==1)
                {
                    outputFile<<"6.1. ����"<<endl;
                    return ; //doTask �Լ�����
                }
                getline(inputFile,str);
            }
        }
    }
}

int main() {
    doTask();
    inputFile.close();
    outputFile.close();
}