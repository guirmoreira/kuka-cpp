#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include <string.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "models.hpp"
#include <vector>
#include <fstream>


Data get_data_from_xml_receive(const char* xml_send)
{
    Data data;

    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> *root_node;

    //doc.parse<0>(xml_send);

    std::ifstream file("xml_send_example.xml");

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    buffer.push_back('\0');

    doc.parse<0>(&buffer[0]);


    root_node = doc.first_node("Rob");

    rapidxml::xml_node<> *rist_node = root_node->first_node("RIst");
        Coordinates r_ist;
        r_ist.set_x(atof(rist_node->first_attribute("X")->value()));
        r_ist.set_y(atof(rist_node->first_attribute("Y")->value()));
        r_ist.set_z(atof(rist_node->first_attribute("Z")->value()));
        r_ist.set_a(atof(rist_node->first_attribute("A")->value()));
        r_ist.set_b(atof(rist_node->first_attribute("B")->value()));
        r_ist.set_c(atof(rist_node->first_attribute("C")->value()));
        data.set_r_ist(r_ist);
    rapidxml::xml_node<> *rsol_node = root_node->first_node("RSol");
        Coordinates r_sol;
        r_sol.set_x(atof(rsol_node->first_attribute("X")->value()));
        r_sol.set_y(atof(rsol_node->first_attribute("Y")->value()));
        r_sol.set_z(atof(rsol_node->first_attribute("Z")->value()));
        r_sol.set_a(atof(rsol_node->first_attribute("A")->value()));
        r_sol.set_b(atof(rsol_node->first_attribute("B")->value()));
        r_sol.set_c(atof(rsol_node->first_attribute("C")->value()));
        data.set_r_sol(r_sol);
    rapidxml::xml_node<> *aipos_node = root_node->first_node("AIPos");
        Axes ai_pos;
        ai_pos.set_a1(atof(aipos_node->first_attribute("A1")->value()));
        ai_pos.set_a2(atof(aipos_node->first_attribute("A2")->value()));
        ai_pos.set_a3(atof(aipos_node->first_attribute("A3")->value()));
        ai_pos.set_a4(atof(aipos_node->first_attribute("A4")->value()));
        ai_pos.set_a5(atof(aipos_node->first_attribute("A5")->value()));
        ai_pos.set_a6(atof(aipos_node->first_attribute("A6")->value()));
        data.set_ai_pos(ai_pos);
    rapidxml::xml_node<> *aspos_node = root_node->first_node("ASPos");
        Axes as_pos;
        as_pos.set_a1(atof(aspos_node->first_attribute("A1")->value()));
        as_pos.set_a2(atof(aspos_node->first_attribute("A2")->value()));
        as_pos.set_a3(atof(aspos_node->first_attribute("A3")->value()));
        as_pos.set_a4(atof(aspos_node->first_attribute("A4")->value()));
        as_pos.set_a5(atof(aspos_node->first_attribute("A5")->value()));
        as_pos.set_a6(atof(aspos_node->first_attribute("A6")->value()));
        data.set_as_pos(as_pos);
    rapidxml::xml_node<> *eipos_node = root_node->first_node("EIPos");
        Axes ei_pos;
        ei_pos.set_a1(atof(eipos_node->first_attribute("E1")->value()));
        ei_pos.set_a2(atof(eipos_node->first_attribute("E2")->value()));
        ei_pos.set_a3(atof(eipos_node->first_attribute("E3")->value()));
        ei_pos.set_a4(atof(eipos_node->first_attribute("E4")->value()));
        ei_pos.set_a5(atof(eipos_node->first_attribute("E5")->value()));
        ei_pos.set_a6(atof(eipos_node->first_attribute("E6")->value()));
        data.set_ei_pos(ei_pos);
    rapidxml::xml_node<> *espos_node = root_node->first_node("ESPos");
        Axes es_pos;
        es_pos.set_a1(atof(espos_node->first_attribute("E1")->value()));
        es_pos.set_a2(atof(espos_node->first_attribute("E2")->value()));
        es_pos.set_a3(atof(espos_node->first_attribute("E3")->value()));
        es_pos.set_a4(atof(espos_node->first_attribute("E4")->value()));
        es_pos.set_a5(atof(espos_node->first_attribute("E5")->value()));
        es_pos.set_a6(atof(espos_node->first_attribute("E6")->value()));
        data.set_es_pos(es_pos);
    rapidxml::xml_node<> *macur_node = root_node->first_node("MACur");
        Axes ma_cur;
        ma_cur.set_a1(atof(macur_node->first_attribute("A1")->value()));
        ma_cur.set_a2(atof(macur_node->first_attribute("A2")->value()));
        ma_cur.set_a3(atof(macur_node->first_attribute("A3")->value()));
        ma_cur.set_a4(atof(macur_node->first_attribute("A4")->value()));
        ma_cur.set_a5(atof(macur_node->first_attribute("A5")->value()));
        ma_cur.set_a6(atof(macur_node->first_attribute("A6")->value()));
        data.set_ma_cur(ma_cur);
    rapidxml::xml_node<> *mecur_node = root_node->first_node("MECur");
        Axes me_cur;
        me_cur.set_a1(atof(mecur_node->first_attribute("E1")->value()));
        me_cur.set_a2(atof(mecur_node->first_attribute("E2")->value()));
        me_cur.set_a3(atof(mecur_node->first_attribute("E3")->value()));
        me_cur.set_a4(atof(mecur_node->first_attribute("E4")->value()));
        me_cur.set_a5(atof(mecur_node->first_attribute("E5")->value()));
        me_cur.set_a6(atof(mecur_node->first_attribute("E6")->value()));
        data.set_me_cur(me_cur);
    rapidxml::xml_node<> *delay_node = root_node->first_node("Delay");
        data.set_delay(atoi(delay_node->first_attribute("D")->value()));
    rapidxml::xml_node<> *digout_node = root_node->first_node("Digout");
        DigitalOutputs dig_out;
        dig_out.set_o1(atoi(digout_node->first_attribute("o1")->value()));
        dig_out.set_o2(atoi(digout_node->first_attribute("o2")->value()));
        dig_out.set_o3(atoi(digout_node->first_attribute("o3")->value()));
        data.set_digital_outputs(dig_out);
    rapidxml::xml_node<> *ftc_node = root_node->first_node("FTC");
        Coordinates ftc;
        ftc.set_x(atof(ftc_node->first_attribute("Fx")->value()));
        ftc.set_y(atof(ftc_node->first_attribute("Fy")->value()));
        ftc.set_z(atof(ftc_node->first_attribute("Fz")->value()));
        ftc.set_a(atof(ftc_node->first_attribute("Mx")->value()));
        ftc.set_b(atof(ftc_node->first_attribute("My")->value()));
        ftc.set_c(atof(ftc_node->first_attribute("Mz")->value()));
        data.set_ftc(ftc);
    rapidxml::xml_node<> *ipoc_node = root_node->first_node("IPOC");
        data.set_ipoc(atoi(ipoc_node->value()));


    return data;
}

//void generate_xml_receive(Coordinates move, Axes rotate, DigitalOutputs dig_out, unsigned int ipoc)
void generate_xml_receive()
{
    // Write xml file =================================
    rapidxml::xml_document<> doc;
    
    rapidxml::xml_node<>* root = doc.allocate_node(rapidxml::node_element, "rootnode");
    root->append_attribute(doc.allocate_attribute("version", "1.0"));
    root->append_attribute(doc.allocate_attribute("type", "example"));
    doc.append_node(root);
    
    rapidxml::xml_node<>* child = doc.allocate_node(rapidxml::node_element, "childnode");
    child->append_attribute(doc.allocate_attribute("A1", "1.0"));
    child->append_attribute(doc.allocate_attribute("A2", "0.3343"));
    child->value("Aqui é o valoooor");
    root->append_node(child);

    std::cout << doc;
    
    // Convert doc to string if needed
    std::string xml_as_string;
    rapidxml::print(std::back_inserter(xml_as_string), doc);
    
    // Save to file
    std::ofstream file_stored("file_stored.xml");
    file_stored << doc;
    file_stored.close();
    doc.clear();
}


















// WORKING CODE TO GET XML
/*
    std::cout << "Parsing my XML send..." << std::endl;

    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> *root_node;

    std::ifstream file("xml_send_example.xml");

    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    buffer.push_back('\0');

    doc.parse<0>(&buffer[0]);

    root_node = doc.first_node("Rob");

    std::cout << "Rob value: " << root_node->first_attribute("Type")->value() << std::endl;

    rapidxml::xml_node<> *ipoc_node = root_node->first_node("IPOC");
    
    std::cout << "IPOC value: " << ipoc_node->value() << std::endl;

    Data data;

    data.set_ipoc(atoi(ipoc_node->value()));

    std::cout << "IPOC: " << data.get_ipoc() << std::endl;
    */