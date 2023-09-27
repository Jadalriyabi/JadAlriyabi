import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication
import getpass
import json
import datetime
import os

# Function to load saved email templates
def load_templates():
    try:
        with open("templates.json", "r") as file:
            return json.load(file)
    except FileNotFoundError:
        return {}

# Function to save email templates to a JSON file
def save_templates(templates):
    with open("templates.json", "w") as file:
        json.dump(templates, file)

# Function to send an email with attachments
def send_email(sender_email, sender_password, recipient_email, subject, message, attachments=[]):
    try:
        # Create an SMTP object
        smtp_server = 'smtp.example.com'
        smtp_port = 587
        smtp = smtplib.SMTP(smtp_server, smtp_port)

        # Start TLS for security
        smtp.starttls()

        # Login to the SMTP server
        smtp.login(sender_email, sender_password)

        # Create a message
        msg = MIMEMultipart()
        msg['From'] = sender_email
        msg['To'] = recipient_email
        msg['Subject'] = subject

        # Attach the message to the email
        msg.attach(MIMEText(message, 'plain'))

        # Attach files
        for attachment in attachments:
            with open(attachment, 'rb') as file:
                part = MIMEApplication(file.read())
            part.add_header('Content-Disposition', f'attachment; filename="{os.path.basename(attachment)}"')
            msg.attach(part)

        # Send the email
        smtp.sendmail(sender_email, recipient_email, msg.as_string())

        # Close the SMTP server
        smtp.quit()

        print(f"Email sent to {recipient_email}")
    except Exception as e:
        print(f"An error occurred: {str(e)}")

# Function to create and save an email template
def create_template():
    templates = load_templates()
    template_name = input("Enter a name for the template: ")
    subject = input("Enter the email subject: ")
    message = input("Enter the email message: ")
    templates[template_name] = {"subject": subject, "message": message}
    save_templates(templates)
    print(f"Template '{template_name}' created and saved.")

# Function to list available email templates
def list_templates():
    templates = load_templates()
    if templates:
        print("Available templates:")
        for template_name in templates:
            print(f"- {template_name}")
    else:
        print("No templates found.")

# Function to send an email using a template
def send_email_with_template(sender_email, sender_password, recipient_email, template_name):
    templates = load_templates()
    if template_name in templates:
        template = templates[template_name]
        send_email(sender_email, sender_password, recipient_email, template["subject"], template["message"])
    else:
        print(f"Template '{template_name}' not found.")

# Main program
while True:
    print("Options:")
    print("1. Send Email")
    print("2. Create Email Template")
    print("3. List Email Templates")
    print("4. Quit")
    
    choice = input("Enter your choice: ")
    
    if choice == "1":
        sender_email = input("Enter your email address: ")
        sender_password = getpass.getpass("Enter your email password: ")
        recipient_email = input("Enter recipient's email address: ")
        subject = input("Enter the email subject: ")
        message = input("Enter the email message: ")
        attachment_paths = input("Enter attachment file paths (comma-separated): ").split(',')
        send_email(sender_email, sender_password, recipient_email, subject, message, attachment_paths)
    elif choice == "2":
        create_template()
    elif choice == "3":
        list_templates()
    elif choice == "4":
        break
    else:
        print("Invalid choice")
