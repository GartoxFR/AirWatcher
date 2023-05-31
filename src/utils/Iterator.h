#pragma once

#include <functional>

template <typename BaseIterator> class SimpleConstIterator {
  public:
    SimpleConstIterator(const BaseIterator& begin, const BaseIterator& end)
        : m_begin(begin), m_end(end) {}

    BaseIterator begin() const { return m_begin; }
    BaseIterator end() const { return m_end; }

  private:
    BaseIterator m_begin;
    BaseIterator m_end;
};

template <typename BaseIterator> class FilteredConstIterator {
  public:
    typedef std::function<bool(const typename BaseIterator::value_type&)>
        filter_type;

    struct filtered_iterator {

        filtered_iterator(const BaseIterator& begin, const BaseIterator& end,
                          filter_type filter)
            : m_begin(begin), m_end(end), m_filter(filter) {

            // Si le début de l'iterator ne passe pas le filtre, on avance
            // l'iterator
            if (!m_filter(**this)) {
                operator++();
            }
        }

        filtered_iterator& operator++() {
            do {
                ++m_begin;
            } while (m_begin != m_end && !m_filter(**this));

            return *this;
        }

        bool operator==(const BaseIterator& other) { return other == m_begin; }

        // typename BaseIterator::value_type operator*() { return *m_begin; }
        const typename BaseIterator::value_type& operator*() {
            return *m_begin;
        }

      private:
        BaseIterator m_begin;
        BaseIterator m_end;
        filter_type m_filter;
    };
    FilteredConstIterator(const BaseIterator& begin, const BaseIterator& end,
                          filter_type filter)
        : m_begin(begin, end, filter), m_end(end) {}

    filtered_iterator begin() const { return m_begin; }
    BaseIterator end() const { return m_end; }

  private:
    filtered_iterator m_begin;
    BaseIterator m_end;
};
