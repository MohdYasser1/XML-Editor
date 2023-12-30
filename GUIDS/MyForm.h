#pragma once
#include "MyForm1.h"

#include <iostream>
#include <msclr\marshal_cppstd.h>//to convert std::string to String ^ and vice versa
#include <msclr/marshal_cppstd.h>
//#include "../xmlprettifier.cpp"
//#include "../xmlminifier.cpp"
//#include "../json.cpp"
#include "../consistency_check.cpp"
//#include "../utils.cpp"
#include "../xmlminifier.cpp"
//#include "../xmlprettifier.cpp"
#include "../compression.cpp"
#include "../undo_redo.cpp"
//#include "../XmlToJson.cpp"




namespace GUIDS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Xml;
	using namespace std;
	using namespace msclr::interop; // Required for string conversions


	//GUIDS::Operation globalOperation;
	// Forward declaration of the Operation class

	// Declare a global object of the Operation class
	//extern Operation globalOperation;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		String^ name = "XML";
		String^ state = "xml";
		//
		//String^ managedString = "Hello, World!";
		//std::string* nativeString = msclr::interop::marshal_as<std::string*>(managedString);

		//// Convert std::string to String^
		//std::string nativeString2 = "Hello, .NET!";
		//System::String^ managedString2 = msclr::interop::marshal_as<String^>(nativeString2);

		//std::string str = msclr::interop::marshal_as<std::string>(textBox1->Text);
		//std::string* str = msclr::interop::marshal_as<std::string*>(jsonMinifier(str));
		//std::string ma = str;

		//System::String^ ms = msclr::interop::marshal_as<String^>(str);//std::string to String ^


		//std::string* text1 = textBox1->Text;
		//std::string* text2 = Marshal::StringToHGlobalUni(textBox2->Text).ToPointer();

		
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button11;


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

	protected:








	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->HideSelection = false;
			resources->ApplyResources(this->textBox1, L"textBox1");
			this->textBox1->Name = L"textBox1";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button12);
			this->panel1->Controls->Add(this->button11);
			this->panel1->Controls->Add(this->button10);
			this->panel1->Controls->Add(this->button9);
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// button12
			// 
			this->button12->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button12, L"button12");
			this->button12->Name = L"button12";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button11
			// 
			this->button11->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button11, L"button11");
			this->button11->Name = L"button11";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button10
			// 
			this->button10->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button10, L"button10");
			this->button10->Name = L"button10";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button9
			// 
			this->button9->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button9, L"button9");
			this->button9->Name = L"button9";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button8
			// 
			this->button8->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button8, L"button8");
			this->button8->Name = L"button8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button7
			// 
			this->button7->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button7, L"button7");
			this->button7->Name = L"button7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button6
			// 
			resources->ApplyResources(this->button6, L"button6");
			this->button6->Name = L"button6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button5, L"button5");
			this->button5->Name = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button4
			// 
			this->button4->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button4, L"button4");
			this->button4->Name = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			// 
			// button3
			// 
			this->button3->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button3, L"button3");
			this->button3->Name = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			// 
			// button2
			// 
			this->button2->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button2, L"button2");
			this->button2->Name = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->AcceptsReturn = true;
			this->textBox2->AcceptsTab = true;
			this->textBox2->AllowDrop = true;
			resources->ApplyResources(this->textBox2, L"textBox2");
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Name = L"textBox2";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged_1);
			// 
			// MyForm
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Stream^ myStream;
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "XML |*.xml| txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 1;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = openFileDialog1->OpenFile()) != nullptr)
		{

			String^ fileName = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
			String^ readFile = File::ReadAllText(fileName);

			// Write complete file path to file path text box
			textBox1->Text = readFile;

			myStream->Close();
		}
	}
	return System::Void();
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		StreamWriter^ sw = gcnew StreamWriter(Application::StartupPath + "\\Saved Files"+"\\"+name+"."+state);
		sw->Write(textBox2->Text);
		sw->Flush();
		sw->Close();

}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//text1 = textBox1->Text;
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	std::string input = msclr::interop::marshal_as<std::string>(textBox1->Text);
	input = checkXML(input); 
	input = newLinesinString(input);
	System::String^ output = msclr::interop::marshal_as<String^>(input);
	textBox2->Text = output; 
	name = "Erorr Detection";
	state = "xml";
}	
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {

	std::string input = msclr::interop::marshal_as<std::string>(textBox1->Text);
	input = XML_2_Json(input);
	input = newLinesinString(input);
	System::String^ output = msclr::interop::marshal_as<String^>(input);
	textBox2->Text = output;

	
	name = "JSON";
	state = "json";
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string input = msclr::interop::marshal_as<std::string>(textBox1->Text);
	input = xmlPrettifier(input);
	//input = nreplaceNewLines(input);
	System::String^ output = msclr::interop::marshal_as<String^>(input);
	textBox2->Text = output;
	name = "Prettifying";
	state = "xml";
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	name = "Compression";
	state = "huf";

	std::string input = msclr::interop::marshal_as<std::string>(textBox1->Text);
	compress(input);
	//System::String^ output = msclr::interop::marshal_as<String^>(input);
	//textBox2->Text = output;
	/*huffman h(input, "CompressedXML.huf");
	h.create_pq();
	h.create_huffman_tree();
	h.calculate_huffman_codes();
	h.coding_save();*/
	//StreamWriter^ sw = gcnew StreamWriter(Application::StartupPath + "\\Saved Files" + "\\" + name + "." + state);
	//sw->Write(textBox2->Text);
	//sw->Flush();
	//sw->Close();
}


	
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	Stream^ myStream1;
	OpenFileDialog^ openFileDialog2 = gcnew OpenFileDialog;
	openFileDialog2->InitialDirectory = "";
	openFileDialog2->Filter = "HUF |*.huf| txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog2->FilterIndex = 1;
	openFileDialog2->RestoreDirectory = true;

	if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream1 = openFileDialog2->OpenFile()) != nullptr)
		{

			String^ fileName = openFileDialog2->InitialDirectory + openFileDialog2->FileName;
			String^ readFile = File::ReadAllText(fileName);
			std::string input = msclr::interop::marshal_as<std::string>(fileName);
			input = decompress(input);
//			input = xmlPrettifier(input);

			input = newLinesinString(input);

			System::String^ output = msclr::interop::marshal_as<String^>(input);
			textBox2->Text = output;


			// Write complete file path to file path text box


			myStream1->Close();
		}
	}


	name = "Decompression";
	state = "huf";
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string input = msclr::interop::marshal_as<std::string>(textBox1->Text);
	input = xmlMinifier(input);
	input = newLinesinString(input);
	System::String^ output = msclr::interop::marshal_as<String^>(input);
	textBox2->Text = output;

	name = "Minifying";
	state = "xml";

}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	
	System::String^ output = msclr::interop::marshal_as<String^>(globalOperation.UNDO());
	//if (output != "NOT FOUND")
	textBox2->Text = output;

}
public: System::Void textBox2_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	std::string input = msclr::interop::marshal_as<std::string>(textBox2->Text);
	if (input != "NOT FOUND")
	globalOperation.addOperation(input);

//	System::String^ outputu = msclr::interop::marshal_as<String^>(globalOperation.UNDO());

	//if (outputu != "NOT FOUND")
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm1 obj;
	obj.ShowDialog();
}
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
	std::string input = msclr::interop::marshal_as<std::string>(textBox1->Text);
	input = correctXML(input);
	input = newLinesinString(input);
	System::String^ output = msclr::interop::marshal_as<String^>(input);
	textBox2->Text = output;

	//corr
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	//Operation op;
	System::String^ output = msclr::interop::marshal_as<String^>(globalOperation.REDO());
	//if (output != "NOT FOUND")
	textBox2->Text = output;
	
}
};
}
