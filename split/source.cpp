GLVM::Core::TCVectorContainer<TCVectorContainer<char>> Split(const char _separator) {
    GLVM::Core::TCVectorContainer<TCVectorContainer<char>> wordsContainer;
    unsigned int outerIndex = 0;
    wordsContainer.Push({});
        
    for(;;++uiCounter) {
        if (pWavefrontObjFileData[uiCounter] == '#') {
            while(pWavefrontObjFileData[uiCounter] != '\n') {
                ++uiCounter;
            }
            continue;
        }
        if (pWavefrontObjFileData[uiCounter] == _separator) {
            wordsContainer.Push({});
            ++outerIndex;
            continue;
        }
        if (pWavefrontObjFileData[uiCounter] == '\n') {
            ++uiCounter;
            return wordsContainer;
        }
        wordsContainer[outerIndex].Push(pWavefrontObjFileData[uiCounter]);
    }
}
