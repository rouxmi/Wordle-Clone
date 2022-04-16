def crypto(word):
    """
    crypto
    @param word: string
    @return mot_crypte : string
    crypo encode un mot par la méthode de césar clé=5
    """
    n=5
    word.lower()
    mot_crypte = ''
    for lettre in word:
        if 97<=ord(lettre)<=122:
            
            cod = ord(lettre)+n
        
            if cod >122:
                cod = 97+ cod%122-1
            mot_crypte += chr(cod)
        else :
            mot_crypte += lettre
    return mot_crypte
    
def decrypto(word):
    """
    decrypto
    @param word: string
    @return mot_decrypte : string
    decrypo decode un mot par la méthode de césar clé=5
    """
    n=5
    mot_decrypte = ''
    for lettre in word:
        if 97<=ord(lettre)<=122:
            
            cod = ord(lettre)-n
            if cod <97:
                cod = 122-(97-cod)+1
            mot_decrypte += chr(cod)
        else :
            mot_decrypte += lettre    
    return mot_decrypte
