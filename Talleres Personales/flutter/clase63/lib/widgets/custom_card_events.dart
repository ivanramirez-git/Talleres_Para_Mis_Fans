import 'package:flutter/material.dart';

class CustonCardEvents extends StatefulWidget {
  final DateTime dateTimeFrom;
  final DateTime dateTimeUntil;
  final String title;
  final bool isUserEvents;
  final IconData icon;
  final Map<String, String> link;
  final String notification;
  final String description;
  // final Map<String, dynamic> options;

  const CustonCardEvents({
    Key? key,
    required this.dateTimeFrom,
    required this.dateTimeUntil,
    required this.title,
    required this.isUserEvents,
    required this.icon,
    required this.link,
    required this.notification,
    required this.description,
    // required this.options,
  }) : super(key: key);

  @override
  State<CustonCardEvents> createState() => _CustonCardEventsState();
}

class _CustonCardEventsState extends State<CustonCardEvents> {
  bool _showDetails = false;
  void _toggleDetails() {
    setState(() {
      _showDetails = !_showDetails;
    });
  }

  String getDateTime() {
    final DateTime now = widget.dateTimeFrom;
    final DateTime until = widget.dateTimeUntil;
    // format the date
    // 11:00 am - 12:00 pm
    String hour_0 = now.hour.toString();
    String minute_0 = now.minute.toString();
    String ampm_0 = now.hour > 12 ? 'pm' : 'am';
    String hour_1 = until.hour.toString();
    String minute_1 = until.minute.toString();
    String ampm_1 = until.hour > 12 ? 'pm' : 'am';
    return '$hour_0:$minute_0$ampm_0/$hour_1:$minute_1$ampm_1';
  }

  void _navigateLink() {
    // TODO: implement navigate Link
    debugPrint('navigateLink');
  }

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      height: 75 + (!_showDetails ? 0 : 75),
      child: Card(
        child: Column(
          children: [
            ListTile(
              leading: Icon(widget.icon),
              // Title  - DateTime
              title: SizedBox(
                width: MediaQuery.of(context).size.width * 0.8,
                child: Row(
                  children: [
                    Text(
                      widget.title,
                      style: const TextStyle(
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                    const SizedBox(width: 10),
                    Text(getDateTime()),
                  ],
                ),
              ),
              trailing: widget.isUserEvents
                  ? SizedBox(
                      width: 120,
                      child: Row(
                        mainAxisAlignment: MainAxisAlignment.spaceBetween,
                        children: [
                          // check rounded button
                          const Icon(Icons.check_box_rounded),
                          const Text('Completed'),
                          InkWell(
                            onTap: _toggleDetails,
                            child: !_showDetails
                                ? const Icon(Icons.arrow_drop_down_rounded,
                                    color: Colors.blue)
                                : const Icon(
                                    Icons.arrow_drop_up_rounded,
                                    color: Colors.blue,
                                  ),
                          ),
                        ],
                      ),
                    )
                  : InkWell(
                      onTap: _toggleDetails,
                      child: !_showDetails
                          ? const Icon(Icons.arrow_drop_down_rounded,
                              color: Colors.blue)
                          : const Icon(
                              Icons.arrow_drop_up_rounded,
                              color: Colors.blue,
                            ),
                    ),
            ),
            if (_showDetails)
              Padding(
                padding:
                    const EdgeInsets.symmetric(vertical: 0, horizontal: 20),
                child: SizedBox(
                  height: 35,
                  child: Row(children: [
                    const Text('Link: '),
                    TextButton(
                        onPressed: _navigateLink,
                        child: Text(widget.link['text'].toString())),
                    const SizedBox(width: 20),
                    const Text('Notification: '),
                    Text(widget.notification.toString()),
                  ]),
                ),
              ),
            if (_showDetails)
              Padding(
                padding:
                    const EdgeInsets.symmetric(vertical: 0, horizontal: 20),
                child: SizedBox(
                  height: 25,
                  child: Row(children: [
                    const Text('Description: '),
                    Text(widget.description.toString()),
                  ]),
                ),
              ),
          ],
        ),
      ),
    );
  }
}
