#include "compressionHelpers.cpp"

using namespace std;

void compress(string file){
    /**
     * This function compresses the XML file content
     * There are 3 steps to the compression:
     * 1. Turning the XML to JSON and then minifying it
     * 2. Use Key-Compression to compress the field names
     * 3. Use Huffman-encoding to compress the final output
     * 
     * @param XML file content to be compressed 
     * 
     * This function should make a new file called CompressedXML.huf
     */

    string compressedFile;
    //XML to minified JSON
    compressedFile = jsonMinifier(XML_2_Json(file));

    //Key-Compression
    compressedFile = keyCompression(compressedFile);
    //Huffman-encoding
    huffmanCoding(compressedFile);
}

string decompress(string compressed_file_path){
    /**
     * This function decompresses the compressed doing the inverse of the compress function.
     * 
     * @param compressed_file the compressed file to be decompressed after converting it to a string
     * @return a string containing the decompressed file contents to be made into a XML-file
     */

    //Huffman Decoding
    string decompressed_file = huffmanDecoding(compressed_file_path);

    //Key-decompression
    decompressed_file = keyDecompress(decompressed_file);
    //Pretifying
    decompressed_file = jsonPrettifier(decompressed_file);
    //Turning back to XML
    decompressed_file = xmlPrettifier(json2XML_Converter(decompressed_file));

    return decompressed_file;
}