function getResult() {
    const input = document.getElementsByTagName("input")[0];
    const inputValue = input.value;
    const cipherId = parseInt(input.id);
    const answer = document.getElementsByClassName("code-container")[0];
    
    console.log(cipherId);
    

    switch (cipherId) {
        case 1:
            if (inputValue.toLowerCase() == "the keycode") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;

        case 2:
            if (inputValue.toLowerCase() == "d o y o u o k e y 0 1" || inputValue.toLowerCase() == "doyouokey01" || inputValue.toLowerCase() == "do you okey 01" || inputValue.toLowerCase() == "do you okey01" || inputValue.toLowerCase() == "doyouokey 01" || inputValue.toLowerCase() == "d/o/y/o/u/o/k/e/y/0/1") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;
        
        case 3:
            if (inputValue.toLowerCase() == "tom13mianovember" || inputValue.toLowerCase() == "tom13mianovember " || inputValue.toLowerCase() == "thomas13mianovember" || inputValue.toLowerCase() == "tom+13+mia+november") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }

            break;

        case 4:
            if (inputValue.toLowerCase() == "the king of all passwords" || inputValue.toLowerCase() == "thekingofallpasswords") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;
        
        case 5:
            if (inputValue.toLowerCase() == "virus" || inputValue.toLowerCase() == "v i r u s" || inputValue.toLowerCase() == "v_i_r_u_s") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }

            break;

        case 6:
            if (inputValue.toLowerCase() == "data" || inputValue.toLowerCase() == "d a t a" || inputValue.toLowerCase() == "d_a_t_a") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;
        
        case 7:
            if (inputValue.toLowerCase() == "proxy" || inputValue.toLowerCase() == "p r o x y" || inputValue.toLowerCase() == "p_r_o_x_y") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;

        case 8:
            if (inputValue.toLowerCase() == "script" || inputValue.toLowerCase() == "s c r i p t") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;
        
        case 9:
            if (inputValue.toLowerCase() == "encrypt" || inputValue.toLowerCase() == "e n c r y p t") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;
        
        case 10:
            if (inputValue.toLowerCase() == "patch" || inputValue.toLowerCase() == "p a t c h") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }            

            break;
        
        case 11:
            if (inputValue.toLowerCase() == "scan" || inputValue.toLowerCase() == "s c a n" || inputValue.toLowerCase() == "s_c_a_n") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }      
            
            break;
        
        case 12:
            if (inputValue.toLowerCase() == "login" || inputValue.toLowerCase() == "l o g i n") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }      
            
            break;

        case 13:
            if (inputValue.toLowerCase() == "hacker" || inputValue.toLowerCase() == "h a c k e r" || inputValue.toLowerCase() == "hacker ") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }      
            
            break;
        
        case 14:
            if (inputValue.toLowerCase() == "user" || inputValue.toLowerCase() == "user " || inputValue.toLowerCase() == "u s e r") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }      
            
            break;

        case 15:
            if (inputValue.toLowerCase() == "1234321" || inputValue.toLowerCase() == "1234321" || inputValue.toLowerCase() == "1 234 321") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }      
            
            break;
        
        case 16:
            if (inputValue.toLowerCase() == "cipher" || inputValue.toLowerCase() == "c i p h e r") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }      
            
            break;
        
        case 17:
            if (inputValue.toLowerCase() == "1101010000" || inputValue.toLowerCase() == "1101010000 " || inputValue.toLowerCase() == "1 1 0 1 0 1 0 0 0 0") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }      
            
            break;
    
        case 18:
            if (inputValue.toLowerCase() == "dark web" || inputValue.toLowerCase() == "d/a/r/k w/e/b" || inputValue.toLowerCase() == "darkweb") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }      
            
            break;

        case 19:
            if (inputValue.toLowerCase() == "code " || inputValue.toLowerCase() == "code") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }      
            
            break;

        case 20:
            if (inputValue.toLowerCase() == "scam" || inputValue.toLowerCase() == "scam ") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }      
            
            break;
         
        case 21:
            if (inputValue.toLowerCase() == "genesis" || inputValue.toLowerCase() == "genesis " || inputValue.toLowerCase() == "první mojžíšova") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;

        case 22:
            if (inputValue.toLowerCase() == "david" || inputValue.toLowerCase() == "david " || inputValue.toLowerCase() == "král david" || inputValue.toLowerCase() == "kral david" || inputValue.toLowerCase() == "kral david " || inputValue.toLowerCase() == "král david ") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;
        
        case 23:
            if (inputValue.toLowerCase() == "antiochii" || inputValue.toLowerCase() == "antiochie" || inputValue.toLowerCase() == "antiochie " || inputValue.toLowerCase() == "antiochii " || inputValue.toLowerCase() == "v antiochii" || inputValue.toLowerCase() == "v antiochii ") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }

            break;

        case 24:
            if (inputValue.toLowerCase() == "ezechiel" || inputValue.toLowerCase() == "ezechiel ") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;
        
        case 25:
            if (inputValue.toLowerCase() == "stepan" || inputValue.toLowerCase() == "stepan " || inputValue.toLowerCase() == "štěpán" || inputValue.toLowerCase() == "štěpán ") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }

            break;

        case 26:
            if (inputValue.toLowerCase() == "buh je s nami" || inputValue.toLowerCase() == "buh je s nama" || inputValue.toLowerCase() == "bůh je s námi" || inputValue.toLowerCase() == "bůh je s námi " || inputValue.toLowerCase() == "bůh je s náma" || inputValue.toLowerCase() == "buh je s nami ") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;
        
        case 27:
            if (inputValue.toLowerCase() == "izajas" || inputValue.toLowerCase() == "izaias" || inputValue.toLowerCase() == "izajas " || inputValue.toLowerCase() == "izaias " || inputValue.toLowerCase() == "izajáš" || inputValue.toLowerCase() == "izajáš " || inputValue.toLowerCase() == "izaiáš" || inputValue.toLowerCase() == "izaiáš ") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;

        case 28:
            if (inputValue.toLowerCase() == "petr" || inputValue.toLowerCase() == "petr ") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;
        
        case 29:
            if (inputValue.toLowerCase() == "letnice" || inputValue.toLowerCase() == "letnice ") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }
            
            break;
        
        case 30:
            if (inputValue.toLowerCase() == "pontius pilat" || inputValue.toLowerCase() == "pilat ponsky" || inputValue.toLowerCase() == "pilát ponský" || inputValue.toLowerCase() == "poncius pilát" || inputValue.toLowerCase() == "poncius pilat") {
                answer.classList.add("show");
            }
            else
            {
                alert("Odpověď nebyla správná!");
            }            

            break;

        default:
            break;
    }
}

function copyText() {
    navigator.clipboard.writeText(document.getElementById("reward").innerText);
    alert("Kód byl zkopírován do schránky.");
}

window.getResult = getResult;
window.copyText = copyText;