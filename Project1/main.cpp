#include<vector>
#include<string>
#include<io.h>
#include<iostream>

using namespace std;

void getFiles(string path, vector<string>& files);
static vector<string> files;

int main()
{

	
	files = {};

	string filePath = "D:\\xuexi\\perl_test";
	//	((CEdit*)GetDlgItem(IDC_EDIT1)).GetWindowText(filePath);
	////获取该路径下的所有文件  
	getFiles(filePath, files);


	int size = files.size();
	for (int i = 0; i < size; i++)
	{
		cout << files[i] << endl;
	}
	system("start D:\\xuexi\\perl_test\\\"1 time.pl\"");//成功打开 但是文件名带空格则必须用双引号括上
	system("PAUSE");
}

static void getFiles(string path, vector<string>& files)
{
	//文件句柄  
	long   hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之  
			//如果不是,加入列表  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}