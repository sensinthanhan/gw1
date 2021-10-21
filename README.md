# ADDING CODE 
# Them ham ip6_send_cmd_hello trong bool authenticate_node (line 850).
# Ham ip6_send_cmd_hello ben trong co ham make_packet_for_node_hello (tuong tu make_packet_for_node, nhung goi tin dc ma hoa bang key defined trc).
# Them ham ip6_send_cmd_key trong void set_node_app_key (line 265).
# Ham ip6_send_cmd_key ben trong co ham make_packet_for_node_key (tuong tu make_packet_for_node, nhung goi tin dc ma hoa bang key defined trc).
# Tuong tu se co ham check_packet_for_node_key() va ham check_packet_for_node_hello() de giai ma cac goi tin nhan tu node (giai ma bang key defined trc).
