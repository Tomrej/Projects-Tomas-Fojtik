import imaplib
import email

host = "imap.seznam.cz"
username = "tomasfoj2007@seznam.cz"
password = "789123654"

mail = imaplib.IMAP4_SSL(host)
mail.login(username, password)
mail.select("inbox")
_, search_data = mail.search(None, "UNSEEN")

for num in search_data[0].split():
    print(num)
    _, data = mail.fetch(num, '(RFC822)')
    # print(data[0])
    _, b = data[0]
    msg_str = str(b)
    print(b)
