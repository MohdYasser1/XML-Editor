#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

string compress(string file){
    /**
     * This function compresses the given xml file after converting it to a string
     * using key-compression and returning the array containing the feilds to be replaced
     * 
     * @param file XML file to be compressed after converting it to a string
     * @return a string containing the compressed file contents to be made into a txt-file
     */

    // TODO: Decide to compress XML or JSON
    // TODO: Decide to use 2 key-compression + huffman encoding or huffman encoding only or other methods
    // TODO: Implement these mehods after dividing them
}

string decompress(string compressed_file){
    /**
     * This function decompresses the compressed doing the inverse of the compress function.
     * 
     * @param compressed_file the compressed file to be decompressed after converting it to a string
     * @return a string containing the decompressed file contents to be made into a XML-file
     */

    // TODO: Decompress the file
}