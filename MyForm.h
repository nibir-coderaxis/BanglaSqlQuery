#pragma once
#include "Markup.h"
#include "addPatients.h"
#using <System.Xml.dll>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>
#include<vector>
#include<string>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>

namespace TextBox {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Xml;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	vector<string >grammer;
	map<wstring, string> mapNumSymbol; 
	map<string, wstring>mapTagger;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  mainTextBox;
	private: System::Windows::Forms::TextBox^  lastTextBox;
	protected:

	protected:

	private: System::Windows::Forms::Button^  sendButton;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  addNewToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  sqlTextbox;
	private: System::Windows::Forms::Label^  lblSqlQuery;
	private: System::Windows::Forms::Label^  lblResult;
	private: System::Windows::Forms::Button^  btnExit;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->mainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->lastTextBox = (gcnew System::Windows::Forms::TextBox());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addNewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sqlTextbox = (gcnew System::Windows::Forms::TextBox());
			this->lblSqlQuery = (gcnew System::Windows::Forms::Label());
			this->lblResult = (gcnew System::Windows::Forms::Label());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainTextBox
			// 
			this->mainTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mainTextBox->Location = System::Drawing::Point(12, 43);
			this->mainTextBox->Multiline = true;
			this->mainTextBox->Name = L"mainTextBox";
			this->mainTextBox->Size = System::Drawing::Size(758, 65);
			this->mainTextBox->TabIndex = 0;
			// 
			// lastTextBox
			// 
			this->lastTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lastTextBox->Location = System::Drawing::Point(413, 221);
			this->lastTextBox->Multiline = true;
			this->lastTextBox->Name = L"lastTextBox";
			this->lastTextBox->ReadOnly = true;
			this->lastTextBox->Size = System::Drawing::Size(371, 86);
			this->lastTextBox->TabIndex = 1;
			// 
			// sendButton
			// 
			this->sendButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sendButton->Location = System::Drawing::Point(12, 114);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(758, 44);
			this->sendButton->TabIndex = 2;
			this->sendButton->Text = L"Process";
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem1,
					this->addNewToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(37, 20);
			this->toolStripMenuItem1->Text = L"File";
			// 
			// addNewToolStripMenuItem
			// 
			this->addNewToolStripMenuItem->Name = L"addNewToolStripMenuItem";
			this->addNewToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->addNewToolStripMenuItem->Text = L"Add New";
			this->addNewToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addNewToolStripMenuItem_Click);
			// 
			// sqlTextbox
			// 
			this->sqlTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sqlTextbox->Location = System::Drawing::Point(12, 221);
			this->sqlTextbox->Multiline = true;
			this->sqlTextbox->Name = L"sqlTextbox";
			this->sqlTextbox->ReadOnly = true;
			this->sqlTextbox->Size = System::Drawing::Size(365, 86);
			this->sqlTextbox->TabIndex = 4;
			this->sqlTextbox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// lblSqlQuery
			// 
			this->lblSqlQuery->AutoSize = true;
			this->lblSqlQuery->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSqlQuery->Location = System::Drawing::Point(129, 201);
			this->lblSqlQuery->Name = L"lblSqlQuery";
			this->lblSqlQuery->Size = System::Drawing::Size(80, 17);
			this->lblSqlQuery->TabIndex = 5;
			this->lblSqlQuery->Text = L"Sql Query";
			// 
			// lblResult
			// 
			this->lblResult->AutoSize = true;
			this->lblResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblResult->Location = System::Drawing::Point(550, 201);
			this->lblResult->Name = L"lblResult";
			this->lblResult->Size = System::Drawing::Size(54, 17);
			this->lblResult->TabIndex = 5;
			this->lblResult->Text = L"Result";
			// 
			// btnExit
			// 
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->Location = System::Drawing::Point(360, 313);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 6;
			this->btnExit->Text = L"EXIT";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::exitButtonClick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 339);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->lblResult);
			this->Controls->Add(this->lblSqlQuery);
			this->Controls->Add(this->sqlTextbox);
			this->Controls->Add(this->sendButton);
			this->Controls->Add(this->lastTextBox);
			this->Controls->Add(this->mainTextBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		array<String^>^ words;
		XmlDocument^ doc = gcnew XmlDocument;
		String ^ idString;
		array<String^>^ inputWords = gcnew array<String^>(50);

		
		
#pragma endregion


		
		

		

		public:System::Void printMsg(string str)
		{
				   mainTextBox->Text = gcnew String(str.c_str());
		}

		public: Void getGrammer()
		{
			//vector<string> gram;
			for each(String ^ str in inputWords)
			{
				if (str == nullptr) break;

				std::string stdString = marshal_as<std::string>(str);

				grammer.push_back(stdString);

				//lastTextBox->Text += (str) ;
			}

			grammer.push_back("$");
			
			//return gram;

		}	


	public:System::Void splitInputText()
	{

			   // mapping the bangla number symbol


			   inputWords->Clear;
			   words->Clear;

			   String ^ inputText = mainTextBox->Text;

			   String^ delimStr = " ,.:\t";

			   array<Char>^ delimiter = delimStr->ToCharArray();



			   words = inputText->Split(delimiter);

			   /*
			   //Display all the book titles.
			   int i = 0;
			   lastTextBox->Text = "";
			   
			   for each (String ^ str in words)
			   {
				   // XmlNodeList^ elemList = doc->GetElementsByTagName(str);
				   mainTextBox->Text += str + " " + i + " " ;
				   map<string,string>::iterator result = mapChar.find(msclr::interop::marshal_as<std::string>(str));
				   if(result == mapChar.end() )
				   {
					   lastTextBox->Text = str + " not found :( ";
					   notFound = true; 
					   return;

				   }
				   else 
					   inputWords[i++] = (gcnew String(result->second.c_str()));
				   lastTextBox->Text += str + " - " +  gcnew String(result->second.c_str()) + " ";

			   }
			   */



			   bool isValue = false;
			   int i = 0;
			   lastTextBox->Text = "";
			   for each (String ^ str in words)
			   {
				   if (isValue)
				   {
					   idString = str ;
					   inputWords[i++] = idString;
					   isValue = false;
					   continue;

					   // number conversion bangla to english
					   /*
					   wstring numString = msclr::interop::marshal_as<std::wstring>(str);

					   for (int k = 0; k < numString.size(); k++)
					   {
						   wstring temp = L"";
						   temp.push_back(numString[k]);

						   idString = idString +  (gcnew String(mapNumSymbol[temp].c_str()));
					   }
					   lastTextBox->Text += " "  + idString;
					   nextId = false;
					   continue;
					   */
				   }

				   XmlNodeList^ elemList = doc->GetElementsByTagName(str);

				   if (elemList->Count == 0)
				   {
					   // lastTextBox->Text = str + " not found :( ";
					   continue;

				   }
				   else
				   {
					   inputWords[i++] = ((elemList[0]->InnerXml));
					   string pos = msclr::interop::marshal_as<std::string>(elemList[0]->InnerXml);
					   mapTagger[pos] = msclr::interop::marshal_as<std::wstring>(str);

					   if (i == 2)
					   {
						   isValue = true;
					   }
					   //lastTextBox->Text += inputWords[i-1]  + " ";
				   }

				   

			   }

			  getGrammer();
	}



	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 doc->Load("name.xml");
				 //xmlReadFunction();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 // 
				 idString = "";
				 lastTextBox->Text = "";
				 sqlTextbox->Text = "";

				
				splitInputText();

				lastTextBox->Text = "";
				sqlTextbox->Text = "";
				if (idString->Length == 0)
					return;

				int tableComponentCount = 0; 

				bool containTable[3] = { false };
				String ^strT = "";

				for each(String ^ str in inputWords)
				{


					strT = strT+str;
					//lastTextBox->Text += str + " " ;

					if (str == "doctor")
					{
						containTable[1] = true;
						tableComponentCount++;
					}
					else if (str == "patient")
					{
						containTable[0] = true;
						tableComponentCount++;
					}
						
				}


				if (tableComponentCount == 1)
				{
					String^ tableName;
					String ^ tableType;
					if (containTable[0])
					{
						tableName = "patientInfo";
						tableType = "patient";
					}
					else
					{
						tableName = "doctorInfo";
						tableType = "doctor";
					}


					String ^ findString = "";
					/*
					int is = 0;

					for each(String ^ str in inputWords)
					{

						//lastTextBox->Text += str + " " + is;

						if (str == nullptr)
							break;

						if (is == 0 && str == "id")
						{
							is++;
						}
						if (is == 1 && idString->Length != 0)
						{
							is++;
						}


						if (is == 2)
						{
							findString = str;
						}
					}

					*/
					//if (findString->Length == 0) return;


						

					String ^ conString = L"datasource = localhost; port = 3306;username=root; password=root";
					MySqlConnection^ conn = gcnew MySqlConnection(conString);
					

					String ^ selectedItems = tableType+"_"+inputWords[3];
					for (int i = 4;; i++)
					{
						if (inputWords[i] == nullptr) break;
						selectedItems += "," + tableType + "_" + inputWords[i];

					}
					// format : "+ tableType +"_" + findString+" 
					String ^ sqlString = "select "+selectedItems+" from database." + tableName + " where " + tableType + "_"+ inputWords[1] +" = '" + inputWords[2] + "';";
					sqlTextbox->Text += sqlString;

					MySqlCommand^ cmd = gcnew MySqlCommand(sqlString, conn);

					MySqlDataReader^ myReader;

					try
					{
						conn->Open();
						myReader = cmd->ExecuteReader();;

						while (myReader->Read())
						{
							for (int i = 3;; i++)
							{
								if (inputWords[i] == nullptr) break;
								String ^ str = inputWords[i];
								wstring word = msclr::interop::marshal_as<std::wstring>(str);
								lastTextBox->Text += gcnew String(mapTagger[word].c_str()) + ": " + myReader[tableType + "_" + inputWords[i]] + "\r\n";
							}
							//lastTextBox->Text += " " + myReader[tableType + "_"+ findString];
						}
						myReader->Close();
						conn->Close();


					}
					catch (Exception ^ ex)
					{
						MessageBox::Show(ex->Message);
					}

				}


				
				
	}
	private: System::Void addNewToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 addPatients ^ addPatientsForm = gcnew addPatients(); 
				 addPatientsForm->Show();
	}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void exitButtonClick(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
};

	
	

	
}