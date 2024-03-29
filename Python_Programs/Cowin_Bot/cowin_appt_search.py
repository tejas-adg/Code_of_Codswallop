# Generated by Selenium IDE
import pytest
import time
import json
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.support import expected_conditions
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities
from selenium.webdriver.support.color import Color
from selenium.common.exceptions import NoSuchElementException
from email_class import Email_Sender

class TestCowinmytest():
    def setup_method(self, method):
        self.driver = webdriver.Firefox(executable_path=r"C:\path\to\geckodriver.exe")
        self.vars = {}
        self.body = ""
        self.sendEmail = False
        e = Email_Sender()
        e.set_receiver_email("dandelipics2612@gmail.com")
        e.set_sender_email("example@gmail.com")
        #add the email password here
        e.set_subject(f"VACCINE SLOT FOUND {time.asctime()}")
        e.set_mime_type("alternative")
        e.set_smtp("smtp.gmail.com", 465)
        self.email_obj = e

    def teardown_method(self, method):
        self.driver.quit()

    def get_main_website(self):
        self.driver.get("https://www.cowin.gov.in/home")

    def send_notif(self):
        self.body += "\n\nThis is NOT A DRILL, go online and register"
        self.email_obj.set_message(self.body)
        self.email_obj.send_email()

    def test_cowin_pin_code_test(self, pin_code):
        print(f"\ncurrent_pin_code = {pin_code}")
        self.driver.find_element(By.ID, "mat-input-0").click()
        self.driver.find_element(By.ID, "mat-input-0").send_keys(pin_code)
        self.driver.find_element(By.CSS_SELECTOR, ".pin-search-btn").click()
        time.sleep(0.5)
        for i in range(1, 100):
            try:
                print(f'Hospital = {self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[1]/div/h5").text.lower()}')
                for j in range(1, 3):
                    try:
                        if "covaxin" in self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[{j}]/div/div[1]/h5").text.lower():
                            print("found covaxin")
                            if "age 18+" in self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[{j}]/div/div[2]/span").text.lower():
                                print("found 18+")
                                if (('rgb(255, 0, 0)' in self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[{j}]/div/a").value_of_css_property('background-color')) and ("booked" in self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[{j}]/div/a").text.lower())):
                                    print("this entry is booked")
                                else:
                                    print(f'{self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[{j}]/div/a").text.lower()} doses available')
                                    self.body += f'\n{self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[{j}]/div/a").text} doses available at {self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[1]/div/h5").text}, pincode: {pin_code} for Ages 18+'
                                    self.sendEmail = True;
                            if "age 45+" in self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[{j}]/div/div[2]/span").text.lower():
                                print("found 45+")
                                if (('rgb(255, 0, 0)' in self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[{j}]/div/a").value_of_css_property('background-color')) and ("booked" in self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[{j}]/div/a").text.lower())):
                                    print("the entry is booked")
                                else:
                                    print(f'{self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[{j}]/div/a").text.lower()} doses available')
                                    self.body += f'\n{self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[{j}]/div/a").text} doses available at {self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[1]/div/h5").text}, pincode: {pin_code} for Ages 45+'
                                    self.sendEmail = True
                        else:
                            print("No covaxin")
                    except NoSuchElementException:
                        print("No more age rows")

                #print(self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[1]/div/a").text.lower())
                #print(self.driver.find_element(By.XPATH, f"/html/body/app-root/div/app-home/div[2]/div/appointment-table/div/div/div/div/div/div/div/div/div/div/div[2]/form/div/div/div[7]/div/div/div/div[{i}]/div/div/div[2]/ul/li[1]/div[1]/div/a").value_of_css_property('background-color'))
                print("\n")
            except NoSuchElementException:
                print("that's all in this pin code")
                break

        if self.sendEmail:
            self.send_notif()
  
e = Email_Sender()
e.set_receiver_email("dandelipics2612@gmail.com")
e.set_sender_email("example@gmail.com")
#Add the password to your email
e.set_subject(f"PROGRAM CRASHED {time.asctime()}")
e.set_mime_type("alternative")
e.set_smtp("smtp.gmail.com", 465)
try:
    t1 = time.time()
    a = TestCowinmytest()
    a.setup_method('a')
    while (1):
        #"560017", "560066", "560003", "560022", "560078", "560093"
        for pin in ["560017", "560066", "560003", "560022", "560078", "560093"]:
            a.get_main_website()
            time.sleep(1.5)
            a.test_cowin_pin_code_test(pin)
            if ((int)((time.time() - t1) / 60)) == 7:
                a.teardown_method('a')
                time.sleep(1.5)
                a.setup_method('a')
                time.sleep(1.5)
                t1 = time.time()
except:
    import traceback, os
    if not os.path.isfile(os.path.join(os.path.abspath(os.path.join(__file__, '..')), 'Log_File.txt')):
        open(os.path.join(os.path.abspath(os.path.join(__file__, '..')), 'Log_File.txt'), 'w').close()
    traceback.print_exc(file = open(os.path.join(os.path.abspath(os.path.join(__file__, '..')), 'Log_File.txt'), "a"))
    e.add_attachment([os.path.join(os.path.abspath(os.path.join(__file__, '..')), 'Log_File.txt')])
    e.set_message("Program has crashed, reason attached")
    e.send_email()
