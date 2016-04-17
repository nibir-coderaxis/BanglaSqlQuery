#pragma once

namespace TextBox {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	/// <summary>
	/// Summary for addPatients
	/// </summary>
	public ref class addPatients : public System::Windows::Forms::Form
	{
	public:
		addPatients(void)
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
		~addPatients()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  boxName;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  boxDisease;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  boxAddress;
	private: System::Windows::Forms::Label^  lblID;
	private: System::Windows::Forms::TextBox^  boxId;


	private: System::Windows::Forms::Button^  btnSubmit;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->boxName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->boxDisease = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->boxAddress = (gcnew System::Windows::Forms::TextBox());
			this->lblID = (gcnew System::Windows::Forms::Label());
			this->boxId = (gcnew System::Windows::Forms::TextBox());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(67, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name";
			// 
			// boxName
			// 
			this->boxName->Location = System::Drawing::Point(218, 77);
			this->boxName->Name = L"boxName";
			this->boxName->Size = System::Drawing::Size(100, 20);
			this->boxName->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(67, 168);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Disease";
			// 
			// boxDisease
			// 
			this->boxDisease->Location = System::Drawing::Point(218, 168);
			this->boxDisease->Name = L"boxDisease";
			this->boxDisease->Size = System::Drawing::Size(100, 20);
			this->boxDisease->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(67, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Address";
			// 
			// boxAddress
			// 
			this->boxAddress->Location = System::Drawing::Point(218, 127);
			this->boxAddress->Name = L"boxAddress";
			this->boxAddress->Size = System::Drawing::Size(100, 20);
			this->boxAddress->TabIndex = 1;
			// 
			// lblID
			// 
			this->lblID->AutoSize = true;
			this->lblID->Location = System::Drawing::Point(67, 44);
			this->lblID->Name = L"lblID";
			this->lblID->Size = System::Drawing::Size(18, 13);
			this->lblID->TabIndex = 0;
			this->lblID->Text = L"ID";
			// 
			// boxId
			// 
			this->boxId->Location = System::Drawing::Point(218, 41);
			this->boxId->Name = L"boxId";
			this->boxId->Size = System::Drawing::Size(100, 20);
			this->boxId->TabIndex = 1;
			// 
			// btnSubmit
			// 
			this->btnSubmit->Location = System::Drawing::Point(163, 220);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(75, 23);
			this->btnSubmit->TabIndex = 2;
			this->btnSubmit->Text = L"Submit";
			this->btnSubmit->UseVisualStyleBackColor = true;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &addPatients::btnSubmit_Click);
			// 
			// addPatients
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(401, 261);
			this->Controls->Add(this->btnSubmit);
			this->Controls->Add(this->boxAddress);
			this->Controls->Add(this->boxId);
			this->Controls->Add(this->boxDisease);
			this->Controls->Add(this->boxName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblID);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"addPatients";
			this->Text = L"addPatients";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSubmit_Click(System::Object^  sender, System::EventArgs^  e) {
				 String ^ conString = L"datasource = localhost; port = 3306;username=root; password=root";
				 MySqlConnection^ conn = gcnew MySqlConnection(conString);
				 MySqlCommand^ cmd = gcnew MySqlCommand("insert into database.patientInfo(patient_id,patient_name,patient_address,patient_disease) values('" + this->boxId->Text + "','" + this->boxName->Text + "','" + this->boxAddress->Text + "','" + this->boxDisease->Text + "');", conn);

				 MySqlDataReader^ myReader;

				 try
				 {
					 conn->Open();
					 myReader = cmd->ExecuteReader();;
					 while (myReader->Read())
					 {

					 }
					 conn->Close();


				 }
				 catch (Exception ^ ex)
				 {
					 MessageBox::Show(ex->Message);
				 }
				 this->Close();
	}
};
}
