#include "compressionHelpers.cpp"

using namespace std;

void compress(string file){
    /**
     * This function compresses the given JSON file after converting it to a string
     * There are 3 steps to the compression:
     * 1. Minify the JSON file
     * 2. Use Key-Compression to compress the field names
     * 3. Use Huffman-encoding to compress the final output
     * 
     * @param file JSON file to be compressed after converting it to a string
     * @return a string containing the compressed file contents to be made into a txt-file
     */

    string compressedFile;
    //XML to JSON
    compressedFile = XML_2_Json(file);

    //Key-Compression
    compressedFile = keyCompression(file);
    // TODO: Implement Huffman-encoding

}

string decompress(string compressed_file){
    /**
     * This function decompresses the compressed doing the inverse of the compress function.
     * 
     * @param compressed_file the compressed file to be decompressed after converting it to a string
     * @return a string containing the decompressed file contents to be made into a XML-file
     */

    string decompressed_file;
    // TODO: Huffman decoding
    // TODO: Key-decompression
    decompressed_file = keyDecompress(compressed_file);
    // TODO: Pretifying 

    return compressed_file;
}