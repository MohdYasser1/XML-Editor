#pragma once
#include <msclr\marshal_cppstd.h>//to convert std::string to String ^ and vice versa
#include "../consistency_check.cpp"

#include "../compression.cpp"
#include <iostream>
#include "../graph.cpp"
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h> 
#include "../PostSearch.cpp"

namespace GUIDS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
		
		 System::String^ xml_text ;
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		MyForm1(String^ data)
		{
			InitializeComponent();
			xml_text = data;

			std::string input = msclr::interop::marshal_as<std::string>(data);

			globalGraph = buildGraph(input);
			std::string MostInfluencerUser = to_string(globalGraph.getMostInfluencerUser(globalGraph));
			std::string MostActiveUser = to_string(globalGraph.getMostActiveUser(globalGraph));
			std::string text = "Most Influencer User: \r\n User" + MostInfluencerUser + "\r\n Most Active User : \r\n User" + MostActiveUser;
			System::String^ output = msclr::interop::marshal_as<String^>(text);
			textBox2->Text = output;
		
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button4;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(4, 4);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(203, 28);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Mutual Connection";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(4, 81);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(203, 28);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Graph Visualization";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(4, 43);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(203, 28);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Suggest a Follow";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->AccessibleDescription = L"";
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Cursor = System::Windows::Forms::Cursors::No;
			this->textBox1->Location = System::Drawing::Point(786, 43);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(268, 24);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox1_TextChanged);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->textBox5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1095, 113);
			this->panel1->TabIndex = 4;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->button4->Location = System::Drawing::Point(833, 75);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(175, 28);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Post search";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::button4_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(273, 46);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(126, 22);
			this->textBox5->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(215, 52);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"User ID";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(405, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"User ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(214, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"User ID";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm1::label2_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(463, 10);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(126, 22);
			this->textBox4->TabIndex = 6;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox4_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(273, 10);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(126, 22);
			this->textBox3->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(20, 135);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox2->Size = System::Drawing::Size(1053, 585);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox2_TextChanged);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1095, 736);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm1";
			this->Text = L"Graph";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	if (textBox5->Text == "") 
		MessageBox::Show("Please enter User ID", "Hai!", MessageBoxButtons::OK, MessageBoxIcon::Warning);

	std::string user1_S = msclr::interop::marshal_as<std::string>(textBox5->Text);
	int user1 = stoi(user1_S);
	std::vector <int> suggest = globalGraph.suggestUsersToFollow(user1);
	std::string text = "Suggested Followers:\r\n";
	for (int i = 0; i < suggest.size(); i++) {
		text += ("User" + to_string(suggest[i]) + "\r\n");
	}

	System::String^ output = msclr::interop::marshal_as<String^>(text);
	textBox2->Text = output;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("If you face any problem with the visualization, run the Graphvic.exe from Projext file Xml-Editor\\", "Hai!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	GraphViz(globalGraph);
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox3->Text == "" || textBox4->Text == "") {
		MessageBox::Show("Please enter User ID", "Hai!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	
	
	}

	std::string user1_S = msclr::interop::marshal_as<std::string>(textBox3->Text);
	int user1 = stoi(user1_S);

	std::string user2_s = msclr::interop::marshal_as<std::string>(textBox4->Text);
	int user2 = stoi(user2_s);

	std::vector <int> mutual = globalGraph.getMutualFollowers(user1, user2);
	std::string text = "Mutual Followers:\r\n";
	for (int i = 0; i < mutual.size(); i++) {
		text += ("User" + to_string(mutual[i]) + "\r\n");
	}
	
	System::String^ output = msclr::interop::marshal_as<String^>(text);
	textBox2->Text = output; 
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string word = msclr::interop::marshal_as<std::string>(textBox1->Text);
	std::string xml = globalGraph.text; 
	//xml = msclr::interop::marshal_as<std::string>(xml);
	std::string text = searchPosts(xml,word);
	text = newLinesinString(text);

	System::String^ output = msclr::interop::marshal_as<String^>(text);

	textBox2->Text = output;
}
};
}
