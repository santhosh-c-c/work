module.exports = {
  formatEventDescription: (github) => {
    const base = `Repository: ${github.repository}\nActor: ${github.actor}`;
    
    if (github.event_name === 'push') {
      return `${base}\nCommits: ${github.event.commits.length}`;
    }
    if (github.event_name === 'pull_request' && github.event.action === 'closed' && github.event.pull_request.merged) {
      return `${base}\nMerged PR: #${github.event.pull_request.number}`;
    }
    return base;
  },

  getEventColor: (github) => {
    switch(github.event_name) {
      case 'push': return 3447003;    // Blue
      case 'pull_request': 
        return github.event.pull_request.merged ? 5763719 :  // Green
               15105570;                                    // Orange
      case 'create': return 2067276;  // Teal
      case 'delete': return 15158332; // Red
      default: return 10181046;       // Purple
    }
  },

  getEventFields: (github) => {
    const fields = [];
    
    if (github.event_name === 'push') {
      github.event.commits.slice(0, 3).forEach(commit => {
        fields.push({
          name: commit.id.substring(0, 7),
          value: commit.message,
          inline: true
        });
      });
    }
    else if (github.event_name === 'pull_request') {
      fields.push({
        name: `PR #${github.event.pull_request.number}`,
        value: github.event.pull_request.title
      });
    }
    else if (github.event_name === 'create' || github.event_name === 'delete') {
      fields.push({
        name: 'Reference',
        value: github.ref
      });
    }

    return fields.length > 0 ? JSON.stringify(fields) : '[]';
  }
}
