import smtplib, ssl, os, re, sys
from html_template import *
from email import encoders
from email.mime.base import MIMEBase
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

sender_email = "shankyhunter1@gmail.com"
receiver_email = "tejasam37@gmail.com"
password = input(f"Enter password for {sender_email} :- ")

message = MIMEMultipart("alternative")
message["From"] = sender_email
message["To"] = receiver_email
message["Subject"] = "Test email"

plain_text = '''\
Hi There!

this is a MIME-Multipart message generated and sent by a python script'''

html = html_tag(
        body_tag(
            p_tag({
                "text" : "Hi there!" + newLine() * 2 + "this is a" + bold("MIME-Multipart") + "message generated by a python script"
                })
            )
        )

message.attach(MIMEText(plain_text, "plain"))
message.attach(MIMEText(html, "html"))

with smtplib.SMTP_SSL("smtp.gmail.com", 465, context = ssl.create_default_context()) as server:
    server.login(sender_email, password)
    server.sendmail(sender_email, receiver_email, message.as_string())


